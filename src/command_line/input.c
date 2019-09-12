/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:36:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/11 21:20:22 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "numbers.h"
#include "output.h"
#include "ft_printf.h"

#include "21sh.h"
#include "lexer.h"
#include "parser.h"
#include "termconf.h"
#include "command_line.h"

static bool		edit_command(char buf[])
{
	int		command_pos_x;

	command_pos_x = g_command_line.cursor_pos.x -1;
	command_pos_x -= get_cursor_offset();
	return (multiline_instert_at(g_command_line.cmds, g_command_line.current_line,
		command_pos_x, buf));
}

static void		get_input(void)
{
	char		buf[5];
	int			ret;

	while (42)
	{
		ft_bzero(buf, 5);
		ret = read(0, buf, 4);
		if (ret == - 1)
			continue ;
		if (handle_enter_key(*(int *)buf))
			break ;
		if (!handle_special_keys(*(int *)buf))
		{
			if (!edit_command(buf))
					fatal(-1, "Can't update command\n");
			move_cursor(ret, 0);
		}
		display_current_line();
	}
	ft_printf("\n");
	debug("get_input end\n");
}

void			handle_input(void)
{
	t_list 		*tkns;
	t_lexer		*lexer;

	tkns = NULL;
	get_cursor_position(&g_command_line.initial_pos);
	while (!tkns)
	{
		display_prompt();
		get_cursor_position(&g_command_line.cursor_pos);
		get_input();
		multiline_debug(g_command_line.cmds);
		lexer = init_lexer();
		lexer->input = multiline_to_char_ptr(g_command_line.cmds);
		tkns = get_token_list(lexer);
		set_prompt(lexer->current_state);
		g_command_line.current_line++;
	}
	debug("***** Parsing part starts below *****\n");
	command_line_history_add_command(multiline_to_char_ptr(g_command_line.cmds));
	// free multiline
	ft_lstiter(tkns, token_debug_info);
	execute_ast_tree(parse(tkns));
	ft_lstdel(&tkns, delete_token);
}
