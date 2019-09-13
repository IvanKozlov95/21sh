/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:37:32 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/13 01:26:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "command_line.h"

/*
** Use the common idiom of 128 + signal number for signal exits.
** Alternative approach is to reset the signal to default handler,
** and immediately raise() it.
** Example:
** exit(128 + signo);
*/

void		sigkill_handler(int signo)
{
	(void)signo;
	ft_printf("\n");
	reset_current_command_edition();
	get_cursor_position(&g_command_line.initial_pos);
	display_prompt();
	get_cursor_position(&g_command_line.cursor_pos);
}
