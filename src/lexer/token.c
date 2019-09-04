/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:30:28 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/22 15:07:51 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "memory.h"

t_token				*create_token(t_lexer *l, char *value)
{
	t_token		*ret;

	ret = ft_memalloc(sizeof(t_token));
	ret->value = value;
	ret->type = l->op_type != unkn ? token_op : token_word;
	return (ret);
}

void		delete_token(void *token_list, size_t size)
{
	t_token		*token;

	token = (t_token *)token_list;
	ft_free(2, token->value, token);
}
