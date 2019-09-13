/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigwinch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 00:44:55 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/13 01:17:55 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "termconf.h"
#include "command_line.h"

/*
**	Handles SIGWINCH aka window resize signal
**	NB! current position of cursor(cursor_pos) will be reset
**	to the end of the current command
*/

void		sigwinch_handler(int signo)
{
	get_cursor_position(&g_command_line.initial_pos);
	g_command_line.initial_pos.x = 1;
	move_cursor_pos(g_command_line.initial_pos.x - 1, g_command_line.initial_pos.y - 1);
	tputs(tgetstr("cd", NULL), g_termconf.descriptor, ft_putc);
	display_current_command();
	get_cursor_position(&g_command_line.cursor_pos);
	(void)signo;
}
