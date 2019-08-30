/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:46:36 by batman            #+#    #+#             */
/*   Updated: 2019/08/29 10:31:33 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LINE_H
# define COMMAND_LINE_H

# include "ft_math.h"
# include "dstring.h"

struct									s_command_line
{
	t_string	*cmd;
	t_point		cursor_pos;
	size_t		prompt_len;
};

typedef struct s_command_line			t_command_line;

extern t_command_line					g_command_line;

/*
**	src/command_line
*/
void									handle_input(void);
void									display_prompt(void);
void									display_cursor(int c);
void									display_command_line(char *input);
void									display_current_command(char *input);
void									init_command_line(void);

/*
**	cursor
*/
void									move_cursor(int horizontal_delta,
	int vertical_delta);
int										get_cursor_position(t_point *cur_pos);

#endif
