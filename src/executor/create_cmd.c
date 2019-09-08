/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:34:00 by batman            #+#    #+#             */
/*   Updated: 2019/09/08 03:49:17 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"
#include "memory.h"
#include "ftstring.h"
#include "shell_command.h"

static void			build_arg_list(t_btree_node *cmd_node, t_shell_command *command)
{
	int					i;
	t_btree_node		*save_ptr;
	t_astnode			*astnode;

	save_ptr = cmd_node;
	while (cmd_node)
	{
		cmd_node = cmd_node->right;
		command->argc++;
	}
	i = 0;
	cmd_node = save_ptr;
	command->argv = ft_memalloc(sizeof(char *) * (command->argc + 1));
	while (cmd_node)
	{
		astnode = (t_astnode *)cmd_node->content;
		command->argv[i] = ft_strdup(astnode->value);
		cmd_node = cmd_node->right;
		i++;
	}
}

t_shell_command		*create_shell_command(t_btree_node *cmd_node, t_innout pipe,
	char *redirect_in, char *redirect_out)
{
	t_shell_command		*command;

	command = ft_memalloc(sizeof(t_shell_command));
	command->pipe = pipe;
	command->redirect_in = redirect_in;
	command->redirect_out = redirect_out;
	build_arg_list(cmd_node, command);
	return (command);
}
