/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:36:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/01 09:36:17 by ikozlov          ###   ########.fr       */
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
		debug("ret: %d %x %x %x %x\n",
			ret, buf[0], buf[1], buf[2], buf[4]);
		if (!handle_special_keys(*(int *)buf))
		{
			if (!string_insert(g_command_line.cmd, buf,
				g_command_line.cursor_pos.x - 1))
					fatal(-1, "Can't update command\n");
			move_cursor(1, 0);
		}
		debug("|%s|\n", g_command_line.cmd->content);
		display_current_command();
	}
}

void			token_debug_info(t_list *elem)
{
	t_token		*token;

	token = elem->content;
	ft_printf("token: |%s| type: %d\n",
		token->value, token->type);
}

void			handle_input(void)
{
	t_list 		*tkns;
	t_lexer		*lexer;

	string_init_content(g_command_line.cmd, 0);
	get_input();
	command_line_history_add_command(g_command_line.cmd->content);
	lexer = init_lexer(g_command_line.cmd->content);
	tkns = get_token_list(lexer);
	ft_lstiter(tkns, token_debug_info);
	execute_ast_tree(parse(tkns));
}
