/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:32:48 by batman            #+#    #+#             */
/*   Updated: 2019/09/11 21:29:37 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "libft.h"

#include "21sh.h"
#include "termconf.h"
#include "command_line.h"

t_termconf			g_termconf;
t_command_line		g_command_line;

/*
**	Gets cursor offset for current line
**	If editing first line or there is a custom prompt(aka quote>)
**	cursro has an offset equal to a prompt length
*/

int					get_cursor_offset(void)
{
	if (g_command_line.current_line == 0 || g_command_line.custom_prompt)
		return (g_command_line.prompt_len);
	return (0);
}

void				move_cursor_pos(int x, int y)
{
	char		*tgoto_ret;

	tgoto_ret = tgoto(g_termconf.cm, x, y);
	tputs(tgoto_ret, g_termconf.descriptor, ft_putc);
	// ft_free(1, tgoto_ret);
}

/*
**	Moves cursor by deltas on x and/or y axises.
**
**	NB! cursor x positon cannot be less or equal to a prompt length + 1
**	Add one because cursor is off by one on both axises
*/

void				move_cursor(int horizontal_delta, int vertical_delta)
{
	int				cursor_offset;

	g_command_line.cursor_pos.x += horizontal_delta;
	if (g_command_line.cursor_pos.x <= get_cursor_offset() + 1)
		g_command_line.cursor_pos.x = get_cursor_offset() + 1;
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
	debug("cursor positon: x %d y %d\n", cur_pos->x, cur_pos->y);
	return (0);
}

void				move_cursor_home(void)
{
	g_command_line.cursor_pos.x = get_cursor_offset();
	move_cursor_pos(g_command_line.cursor_pos.x, g_command_line.cursor_pos.y - 1);
}

void				move_cursor_end(void)
{
	t_multiline		*cmds;

	cmds = g_command_line.cmds;
	g_command_line.cursor_pos.x = g_command_line.prompt_len
		+ cmds->lanes[g_command_line.current_line]->length + 1;
	move_cursor_pos(g_command_line.cursor_pos.x - 1,
		g_command_line.cursor_pos.y - 1);
}
