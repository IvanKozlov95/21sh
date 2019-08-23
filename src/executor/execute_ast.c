/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:42 by batman            #+#    #+#             */
/*   Updated: 2019/08/23 16:20:13 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "btree.h"
#include "shell_command.h"

// todo: static for local func ???

void		execute_cmd(t_btree_node *cmd)
{
	t_shell_command		*command;
	t_builtin_func		builtin_func;

	command = create_shell_command(cmd);
	builtin_func = get_builtin_func(command->argv[0]);
	if (builtin_func)
		builtin_func(*command->argv, command->argv + 1);
	else
		execute_shell_command(command);
	delete_shell_command(command);
}

void		execute_job(t_btree_node *job)
{
	execute_cmd(job);
}

void		execute_program(t_btree_node *program)
{
	if (!program)
		return ;
	execute_job(program);
}

void		execute_ast_tree(t_btree_node *ast)
{
	execute_program(ast);
}

