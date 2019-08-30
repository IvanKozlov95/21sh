/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:50:20 by batman            #+#    #+#             */
/*   Updated: 2019/08/29 10:32:47 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "memory.h"

#include "21sh.h"
#include "command_line.h"

t_command_line		g_command_line;

void		init_command_line(void)
{
	ft_bzero(&g_command_line.cursor_pos, sizeof(t_point));
	if (get_cursor_position(&g_command_line.cursor_pos))
		fatal(errno, "Couldn't get cursor pos\n");
	g_command_line.cmd = NULL;
}
