/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:30:28 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/10 04:49:15 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"

#include "21sh.h"
#include "lexer.h"

static char		*stringify_token_type(int type)
{
	static char	*types[] = {
		"word", "operator", "end of input",
	};

	if (type < 0 || type >= sizeof(types) / sizeof(char *))
		return ("unknown");
	return (types[type]);
}

void			token_debug_info(t_list *elem)
{
	t_token		*token;

	token = elem->content;
	debug("token: |%s| type: %s\n",
		token->value, stringify_token_type(token->type));
}

t_token			*create_token(t_lexer *l, char *value)
{
	t_token		*ret;

	ret = ft_memalloc(sizeof(t_token));
	ret->value = ft_strdup(value);
	ret->type = l->op_type != unkn ? token_op : token_word;
	debug("created token with value |%s|\n", ret->value);
	return (ret);
}

void			delete_token(void *token_list, size_t size)
{
	t_token		*token;

	token = (t_token *)token_list;
	ft_free(2, token->value, token);
}
