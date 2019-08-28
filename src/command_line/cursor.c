/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:32:48 by batman            #+#    #+#             */
/*   Updated: 2019/08/27 18:27:50 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "libft.h"

#include "21sh.h"
#include "termconf.h"
#include "command_line.h"

t_termconf			g_termconf;
t_command_line		g_command_line;

void				move_cursor(int horizontal_delta, int vertical_delta)
{
	g_command_line.cursor_pos.x += horizontal_delta;
	g_command_line.cursor_pos.x = g_command_line.cursor_pos.x < 0
		? 0 : g_command_line.cursor_pos.x;
	g_command_line.cursor_pos.y += vertical_delta;
	g_command_line.cursor_pos.y = g_command_line.cursor_pos.y < 0
		? 0 : g_command_line.cursor_pos.y;
	tputs(tgoto(g_termconf.cm,
		g_command_line.cursor_pos.x,
		g_command_line.cursor_pos.y - 1), 1, ft_putc);
}

int					get_cursor_position(t_point *cur_pos)
{
	int			i;
	char		ch;
	int			ret;
	char		buf[GNR_BUF_SIZE];

	SEND_CURPOS_SQN(g_termconf.descriptor);
	i = 0;
	ch = 0;
	ft_bzero(buf, GNR_BUF_SIZE);
	while (ch != 'R')
	{
		ret = read(STDIN_FILENO, &ch, 1);
		if (ret == -1)
			break ;
		buf[i++] = ch;
	}
	if (i < 2)
		return (errno = error_cur_pos);
	i = 0;
	while (buf[i] && !ft_isdigit(buf[i]))
		i++;
	cur_pos->y = ft_atoi(buf + i);
	cur_pos->x = ft_atoi(buf + ft_strchri(buf, ';') + 1);
	return (0);
}
