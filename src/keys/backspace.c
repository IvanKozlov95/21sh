/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 23:10:14 by batman            #+#    #+#             */
/*   Updated: 2019/08/29 11:03:27 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "keys.h"

#include "command_line.h"

static void		delete_one_char(void)
{
	string_splice(g_command_line.cmd, g_command_line.cursor_pos.x - 2, 1);
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
