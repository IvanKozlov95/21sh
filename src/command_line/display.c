/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:23:06 by batman            #+#    #+#             */
/*   Updated: 2019/08/27 18:08:17 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"
#include "ft_printf.h"

#include "termconf.h"
#include "command_line.h"

t_command_line		g_command_line;

void		display_command_line(char *input)
{
	ft_printf("%s", input + g_command_line.cursor_pos.x);
}

void		display_current_command(char *input)
{
	tputs(tgetstr("cb", NULL), g_termconf.descriptor, ft_putc);
	tputs(tgetstr("ce", NULL), g_termconf.descriptor, ft_putc);
	tputs(tgoto(g_termconf.cm,
		0, g_command_line.cursor_pos.y - 1),
		g_termconf.descriptor, ft_putc);
	display_prompt();
	ft_printf("%s", input);
	tputs(tgoto(g_termconf.cm,
		g_command_line.cursor_pos.x - 1, g_command_line.cursor_pos.y - 1),
		g_termconf.descriptor, ft_putc);
}
