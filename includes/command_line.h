/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:46:36 by batman            #+#    #+#             */
/*   Updated: 2019/09/11 21:28:07 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_H
# define COMMAND_LINE_H

# include "dlist.h"
# include "ft_math.h"
# include "dstring.h"

# include "lexer.h"
# include "multiline.h"

struct									s_history
{
	t_dlist		*list;
	t_dlist		*last_item;
	t_dlist		*active_item;
};

struct									s_command_line
{
	t_multiline			*cmds;
	size_t				current_line;
	struct s_history	history;
	t_point				initial_pos;
	t_point				cursor_pos;
	size_t				prompt_len;
	char				*custom_prompt;
};

typedef struct s_command_line			t_command_line;

extern t_command_line					g_command_line;

/*
**	src/command_line
*/
void									handle_input(void);
void									display_prompt(void);
void									set_prompt(t_fsm_state state);
void									display_cursor(int c);
void									display_current_command(void);
void									display_current_line(void);
void									init_command_line(void);
void									destroy_command_line(void);

/*
**	cursor
*/
int										get_cursor_offset(void);
void									move_cursor(int horizontal_delta,
	int vertical_delta);
void									move_cursor_pos(int x, int y);
void									move_cursor_home(void);
void									move_cursor_end(void);
int										get_cursor_position(t_point *cur_pos);

/*
**	history
*/
void									command_line_history_move_active(
	int direction);
void									command_line_history_add_command(
	char *command);

#endif
