/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:23:42 by batman            #+#    #+#             */
/*   Updated: 2019/09/01 18:05:22 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "btree.h"
#include "parser.h"
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

void		execute_program(t_btree_node *program_node)
{
	t_astnode		*ast_program;

	if (!program_node)
		return ;
	ast_program = program_node->content;
	if (ast_program == NULL)
	{
		execute_program(program_node->left);
		execute_program(program_node->right);
	}
	else
		execute_job(program_node);
}

void		execute_ast_tree(t_btree_node *ast)
{
	execute_program(ast);
}

