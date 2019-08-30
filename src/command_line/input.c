/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:36:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/29 11:37:37 by batman           ###   ########.fr       */
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

	string_destroy(g_command_line.cmd, false);
	g_command_line.cmd = string_init(0);
	while (42)
	{
		ft_bzero(buf, 5);
		ret = read(0, buf, 4);
		if (buf[0] == '\n')
			break ;
		if (!handle_special_keys(*(int *)buf))
		{
			string_append(g_command_line.cmd, buf);
			move_cursor(1, 0);
		}
		display_current_command(g_command_line.cmd->content);
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

	get_input();
	lexer = init_lexer(g_command_line.cmd->content);
	tkns = get_token_list(lexer);
	ft_lstiter(tkns, token_debug_info);
	execute_ast_tree(parse(tkns));
}
