/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 07:18:27 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/11 21:35:41 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"

#include "multiline.h"
#include "command_line.h"

void	debug(char *fmt, ...);

static void		command_line_history_display_active_item(void)
{
	char	*history_command;

	history_command = NULL;
	if (g_command_line.history.active_item)
	{
		history_command = ft_memalloc(
			g_command_line.history.active_item->content_size + 1);
		ft_memcpy(history_command, g_command_line.history.active_item->content,
			g_command_line.history.active_item->content_size);
	}
	multiline_destroy(g_command_line.cmds);
	if (history_command)
		g_command_line.cmds = multiline_init_from_char_ptr(history_command);
	ft_free(1, history_command);
	display_current_command();
	// todo check for null
	g_command_line.current_line = g_command_line.cmds->count - 1;
	get_cursor_position(&g_command_line.cursor_pos);
}

void			command_line_history_move_active(int direction)
{
	if (g_command_line.history.active_item == NULL)
		g_command_line.history.active_item = g_command_line.history.last_item;
	else
	{
		if (direction == 1 && g_command_line.history.active_item)
			g_command_line.history.active_item =
				g_command_line.history.active_item->next;
		else if (direction == -1 && g_command_line.history.active_item->prev)
			g_command_line.history.active_item =
				g_command_line.history.active_item->prev;
	}
	command_line_history_display_active_item();
}

void			command_line_history_add_command(char *command)
{
	size_t		command_len;
	t_dlist		*new_history_item;

	if (!command || (command_len = ft_strlen(command)) == 0)
		return ;
	new_history_item = dlstnew(command, command_len);
	if (g_command_line.history.list == NULL)
	{
		g_command_line.history.list = new_history_item;
		g_command_line.history.last_item = new_history_item;
	}
	else
	{
		dlstaddback(&g_command_line.history.list, new_history_item);
		g_command_line.history.last_item =
			g_command_line.history.last_item->next;
	}
	debug("added |%s| to history\n", command);
}
