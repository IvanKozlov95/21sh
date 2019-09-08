/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_command.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:31:34 by batman            #+#    #+#             */
/*   Updated: 2019/09/07 23:23:52 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_COMMAND_H
# define SHELL_COMMAND_H

#include "btree.h"

struct								s_innout
{
	int			in;
	int			out;
};

typedef struct s_innout				t_innout;

struct								s_shell_command
{
	int			argc;
	char		**argv;
	t_innout	pipe;
	t_innout	redirect;
};

typedef struct s_shell_command		t_shell_command;

#endif

/*
**	src/shell_command/create.c
*/
t_shell_command		*create_shell_command(t_btree_node *cmd_node,
	t_innout pipe, t_innout redirect);

/*
**	src/shell_command/delete.c
*/
void				delete_shell_command(t_shell_command *command);

/*
**	src/shell_command/execute_cmd.c
*/
void				execve_wrapper(char *path, t_shell_command *cmd);
void				execute_shell_command(t_shell_command *command);

/*
**	src/executor/empty_innout
*/
t_innout			empty_innout(void);
