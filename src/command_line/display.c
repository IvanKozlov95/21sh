/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:23:06 by batman            #+#    #+#             */
/*   Updated: 2019/09/01 22:52:46 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"
#include "ft_printf.h"

#include "termconf.h"
#include "command_line.h"

t_command_line		g_command_line;

void		clear_current_command(void)
{
	string_destroy(g_command_line.cmd, false);
	display_prompt();
	get_cursor_position(&g_command_line.cursor_pos);
}

void		display_current_command(void)
{
	tputs(tgoto(g_termconf.cm,
		g_command_line.prompt_len, g_command_line.cursor_pos.y - 1),
		g_termconf.descriptor, ft_putc);
	tputs(tgetstr("ce", NULL), g_termconf.descriptor, ft_putc);
	ft_printf("%s", g_command_line.cmd->content);
	tputs(tgoto(g_termconf.cm,
		g_command_line.cursor_pos.x - 1, g_command_line.cursor_pos.y - 1),
		g_termconf.descriptor, ft_putc);
}
