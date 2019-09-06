/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:42 by batman            #+#    #+#             */
/*   Updated: 2019/09/06 05:42:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "21sh.h"
#include "btree.h"
#include "parser.h"
#include "shell_command.h"

// todo: static for local func ???

void		execute_cmd(t_btree_node *cmd, int pipe_read, int pipe_write)
{
	t_shell_command		*command;
	t_builtin_func		builtin_func;

	command = create_shell_command(cmd);
	command->pipe_in = pipe_read;
	command->pipe_out= pipe_write;
	builtin_func = get_builtin_func(command->argv[0]);
	if (builtin_func)
		builtin_func(*command->argv, command->argv + 1);
	else
		execute_shell_command(command);
	delete_shell_command(command);
}

void		execute_job(t_btree_node *job)
{
	execute_cmd(job, 0, 0);
}

void		execute_pipe(t_btree_node *pipe_node)
{
	int		pipefd[2];
	int		piperead;
	int		pipewrite;

	debug("executing pipeline node\n");
	if (pipe(pipefd) == -1)
		fatal(errno, "pipe fail\n");
	piperead = pipefd[0];
	pipewrite = pipefd[1];
	execute_cmd(pipe_node->left, 0, pipewrite);
	close(pipewrite);
	execute_cmd(pipe_node->right, piperead, 0);
	close(piperead);
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

