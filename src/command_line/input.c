/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:36:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/22 13:17:31 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "dstring.h"
#include "ft_printf.h"

static char		*get_input(void)
{
	t_string	*s;
	char		buf[2];
	int			ret;

	buf[1] = 0;
	s = string_init(0);
	while ((ret = read(0, buf, 1)) && buf[0] != '\n')
		string_append(s, buf);
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
	parse(tkns);
}
