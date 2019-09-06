/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:31:34 by batman            #+#    #+#             */
/*   Updated: 2019/09/06 05:00:52 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_COMMAND_H
# define SHELL_COMMAND_H

#include "btree.h"

struct								s_shell_command
{
	int			argc;
	char		**argv;
	int			pipe_in;
	int			pipe_out;
};

typedef struct s_shell_command		t_shell_command;

#endif

/*
**	src/shell_command/create.c
*/
t_shell_command		*create_shell_command(t_btree_node *cmd_node);

/*
**	src/shell_command/delete.c
*/
void				delete_shell_command(t_shell_command *command);

/*
**	src/shell_command/delete.c
*/
void				execute_shell_command(t_shell_command *command);
