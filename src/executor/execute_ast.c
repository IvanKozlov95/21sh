/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:42 by batman            #+#    #+#             */
/*   Updated: 2019/09/08 04:25:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "21sh.h"
#include "btree.h"
#include "parser.h"
#include "shell_command.h"

// todo: static for local func ???

void		execute_cmd(t_btree_node *cmd, t_innout pipe,
	char *redirect_in, char *redirect_out)
{
	t_shell_command		*command;
	t_builtin_func		builtin_func;

	command = create_shell_command(cmd, pipe, redirect_in, redirect_out);
	builtin_func = get_builtin_func(command->argv[0]);
	if (builtin_func)
		builtin_func(*command->argv, command->argv + 1);
	else
		execute_shell_command(command);
	delete_shell_command(command);
}

void		execute_redirect(t_btree_node *command_node)
{
	t_btree_node		*redirect_node;
	t_astnode			*redirect;

	debug("Executing redirect\n");
	redirect_node = command_node->right;
	redirect = GETAST(redirect_node);
	command_node->right = redirect_node->right;
	if (redirect->type == ast_redirect_out)
		execute_cmd(command_node, empty_innout(), NULL, redirect->value);
	else if (redirect->type == ast_redirect_in)
		execute_cmd(command_node, empty_innout(), redirect->value, NULL);
	command_node->right = redirect_node;
}

void		execute_job(t_btree_node *job)
{
	execute_cmd(job, empty_innout(), NULL, NULL);
}

void		execute_simple_command(t_btree_node *command_node)
{
	if (command_node->right
		&& (((GETAST(command_node->right)->type == ast_redirect_out))
		||((GETAST(command_node->right)->type == ast_redirect_in))))
		execute_redirect(command_node);
	else
		execute_job(command_node);
}

void		execute_pipe(t_btree_node *pipe_node)
{
	int			pipefd[2];
	t_innout	pipe_read;
	t_innout	pipe_write;

	debug("executing pipeline node\n");
	if (pipe(pipefd) == -1)
		fatal(errno, "pipe fail\n");
	pipe_read = empty_innout();
	pipe_write = empty_innout();
	pipe_read.in = pipefd[0];
	pipe_write.out = pipefd[1];
	execute_cmd(pipe_node->left, pipe_write, NULL, NULL);
	close(pipe_write.out);
	execute_cmd(pipe_node->right, pipe_read,  NULL, NULL);
	close(pipe_read.in);
}

void		execute_program(t_btree_node *program_node)
{
	t_astnode		*ast_program;

	if (!program_node)
		return ;
	ast_program = program_node->content;
	if (ast_program->type == ast_pipe)
		execute_pipe(program_node);
	else
		execute_simple_command(program_node);
}

void		execute_ast_tree(t_btree_node *ast)
{
	execute_program(ast);
}

