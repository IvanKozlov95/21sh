/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:42 by batman            #+#    #+#             */
/*   Updated: 2019/09/07 23:28:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "21sh.h"
#include "btree.h"
#include "parser.h"
#include "shell_command.h"

// todo: static for local func ???

void		execute_cmd(t_btree_node *cmd, t_innout pipe, t_innout redirect)
{
	t_shell_command		*command;
	t_builtin_func		builtin_func;

	command = create_shell_command(cmd, pipe, redirect);
	builtin_func = get_builtin_func(command->argv[0]);
	if (builtin_func)
		builtin_func(*command->argv, command->argv + 1);
	else
		execute_shell_command(command);
	delete_shell_command(command);
}

void		execute_job(t_btree_node *job)
{
	execute_cmd(job, empty_innout(), empty_innout());
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
	execute_cmd(pipe_node->left, pipe_write, empty_innout());
	close(pipe_write.out);
	execute_cmd(pipe_node->right, pipe_read, empty_innout());
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
		execute_job(program_node);
}

void		execute_ast_tree(t_btree_node *ast)
{
	execute_program(ast);
}

