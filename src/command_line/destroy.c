/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:58:46 by ikozlov           #+#    #+#             */
/*   Updated: 2019/08/31 12:07:46 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

#include "command_line.h"

static void		delete_command_from_history(void *command_in_history, size_t command_len)
{
	ft_free(1, command_in_history);
}

/*
**	Cleaup function. Call at exit.
*/

void			destroy_command_line(void)
{
	dlstdel(&g_command_line.history.list, delete_command_from_history);
	string_destroy(g_command_line.cmd, false);
	ft_free(1, g_command_line);
}
