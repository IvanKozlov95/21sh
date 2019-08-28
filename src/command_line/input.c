/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:36:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/27 15:58:11 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dstring.h"
#include "numbers.h"
#include "output.h"
#include "ft_printf.h"

#include "21sh.h"
#include "lexer.h"
#include "parser.h"
#include "termconf.h"
#include "command_line.h"

static char		*get_input(void)
{
	t_string	*s;
	char		buf[5];
	int			ret;

	s = string_init(0);
	while (42)
	{
		ft_bzero(buf, 5);
		ret = read(0, buf, 4);
		if (buf[0] == '\n')
			break ;
		else if (handle_navigation_keys(CHARPTR_TO_INT(buf)))
			display_current_command(s->content);
		else
		{
			string_append(s, buf);
			move_cursor(1, 0);
			display_current_command(s->content);
		}
	}
	return (string_destroy(s, true));
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
	char		*input;
	t_lexer		*lexer;

	input = get_input();
	lexer = init_lexer(input);
	tkns = get_token_list(lexer);
	ft_lstiter(tkns, token_debug_info);
	execute_ast_tree(parse(tkns));
}
