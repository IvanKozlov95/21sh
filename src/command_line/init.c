/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:50:20 by batman            #+#    #+#             */
/*   Updated: 2019/09/11 15:13:06 by ikozlov          ###   ########.fr       */
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
	ft_bzero(&g_command_line.initial_pos, sizeof(t_point));
	ft_bzero(&g_command_line.history, sizeof(struct s_history));
	if (get_cursor_position(&g_command_line.initial_pos))
		fatal(errno, "Couldn't get cursor pos\n");
	g_command_line.prompt_len = 0;
}
