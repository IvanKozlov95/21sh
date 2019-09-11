/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 22:23:06 by batman            #+#    #+#             */
/*   Updated: 2019/09/11 16:02:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output.h"
#include "ft_printf.h"

#include "termconf.h"
#include "command_line.h"

void		display_current_line(void)
{
	char		*togo_ret;
	t_string	*current_line;

	debug("display_current_line\n");
	togo_ret = tgoto(g_termconf.cm,
		g_command_line.prompt_len, g_command_line.cursor_pos.y - 1);
	tputs(togo_ret, g_termconf.descriptor, ft_putc);
	tputs(tgetstr("ce", NULL), g_termconf.descriptor, ft_putc);
	current_line = g_command_line.cmds->lanes[g_command_line.current_line];
	if (current_line)
		ft_printf("%s", current_line->content);
	togo_ret = tgoto(g_termconf.cm,
		g_command_line.cursor_pos.x - 1, g_command_line.cursor_pos.y - 1);
	tputs(togo_ret, g_termconf.descriptor, ft_putc);
}

void		display_current_command(void)
{
	char		*togo_ret;
	char		*joined_command;

	debug("display_current_command\n");
	togo_ret = tgoto(g_termconf.cm,
		g_command_line.initial_pos.x - 1, g_command_line.initial_pos.y - 1);
	tputs(togo_ret, g_termconf.descriptor, ft_putc);
	tputs(tgetstr("ce", NULL), g_termconf.descriptor, ft_putc);
	joined_command = multiline_to_char_ptr(g_command_line.cmds);
	display_prompt();
	ft_printf("%s", joined_command);
	togo_ret = tgoto(g_termconf.cm,
		g_command_line.cursor_pos.x - 1, g_command_line.cursor_pos.y - 1);
	tputs(togo_ret, g_termconf.descriptor, ft_putc);
}
