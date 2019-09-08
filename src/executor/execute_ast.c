/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:42 by batman            #+#    #+#             */
/*   Updated: 2019/09/08 11:21:27 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "21sh.h"
#include "btree.h"
#include "parser.h"
#include "shell_command.h"

// todo: static for local func ???

void		execute_cmd(t_btree_node *cmd, t_innout pipe,
	char *redirect_in, char *redirect_out, bool save_redirect_out_content)
{
	t_shell_command		*command;
	t_builtin_func		builtin_func;

	command = create_shell_command(cmd, pipe, redirect_in, redirect_out);
	command->save_redirect_out_content = save_redirect_out_content;
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
		execute_cmd(command_node, empty_innout(), NULL, redirect->value, false);
	else if (redirect->type == ast_redirect_out_save_content)
		execute_cmd(command_node, empty_innout(), NULL, redirect->value, true);
	else if (redirect->type == ast_redirect_in)
		execute_cmd(command_node, empty_innout(), redirect->value, NULL, false);
	command_node->right = redirect_node;
}

void		execute_job(t_btree_node *job)
{
	execute_cmd(job, empty_innout(), NULL, NULL, false);
}

void		execute_simple_command(t_btree_node *command_node)
{
	t_astnode		*redirect;

	if (command_node->right)
	{
		redirect = GETAST(command_node->right);
		if (redirect->type == ast_redirect_out
		||redirect->type ==  ast_redirect_in
		|| redirect->type == ast_redirect_out_save_content)
			return (execute_redirect(command_node));
	}
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
	execute_cmd(pipe_node->left, pipe_write, NULL, NULL, false);
	close(pipe_write.out);
	execute_cmd(pipe_node->right, pipe_read,  NULL, NULL, false);
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

