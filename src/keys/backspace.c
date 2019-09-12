/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:10:14 by batman            #+#    #+#             */
/*   Updated: 2019/09/11 21:21:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "keys.h"

#include "command_line.h"

/*
**	Deletes one character from cursor positon.
**	Substract prompt_len because prompt is not a part of a command.
**	Substract one because real cursor position is off by one on both axises.
**	Substract one because god knows.
*/

static void		delete_one_char(void)
{
	int			cursor_offset;

	cursor_offset = get_cursor_offset();
	string_splice(g_command_line.cmds->lanes[g_command_line.current_line],
		g_command_line.cursor_pos.x - cursor_offset - 2, 1);
	move_cursor(-1, 0);
}

bool			handle_backspace_key(int key)
{
	if (key == KBSPACE)
	{
		delete_one_char();
		return (true);
	}
	return (false);
}
