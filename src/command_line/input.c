/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:36:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/10 05:05:02 by ikozlov          ###   ########.fr       */
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
		if (buf[0] == '\n')
			break ;
		if (!handle_special_keys(*(int *)buf))
		{
			if (!string_insert(g_command_line.cmd, buf,
				g_command_line.cursor_pos.x - g_command_line.prompt_len - 1))
					fatal(-1, "Can't update command\n");
			move_cursor(ret, 0);
		}
		debug("|%s|\n", g_command_line.cmd->content);
		display_current_command();
	}
	ft_printf("\n");
}

void			handle_input(void)
{
	t_list 		*tkns;
	t_list		*last_token;
	t_lexer		*lexer;

	lexer = init_lexer();
	tkns = NULL;
	last_token = NULL;
	while (!last_token || IS_EOI_TOKEN(last_token))
	{
		display_prompt();
		get_cursor_position(&g_command_line.cursor_pos);
		string_init_content(g_command_line.cmd, 0);
		get_input();
		lexer->input = g_command_line.cmd->content;
		last_token = get_token_list(lexer, &tkns);
		// debug("last token ptr %p\n", last_token);
		// if (last_token)
			// token_debug_info(last_token);
		set_prompt(lexer->current_state);
	}
	debug("Done getting input\n");
	command_line_history_add_command(g_command_line.cmd->content);
	ft_free(1, g_command_line.cmd->content);
	ft_lstiter(tkns, token_debug_info);
	execute_ast_tree(parse(tkns));
	ft_lstdel(&tkns, delete_token);
}
