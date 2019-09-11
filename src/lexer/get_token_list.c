/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:37:49 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/11 14:54:50 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "lexer.h"
#include "memory.h"

static t_token			*eoi_token(void)
{
	t_token		*eoi_token;

	eoi_token = ft_memalloc(sizeof(t_token));
	debug("created eoi\n");
	eoi_token->type = token_eoi;
	return (eoi_token);
}

t_list				*get_token_list(t_lexer *lexer)
{
	t_token			*tkn;
	t_list			*new_elem;
	t_list			*token_list;

	debug("get_token_list start\n");
	token_list = NULL;
	while ((tkn = recognize_token(lexer)))
	{
		new_elem = ft_lstnew(tkn, sizeof(t_token));
		LST_ADDCREATE(token_list, new_elem);
		ft_free(1, tkn);
	}
	if (!tkn && (lexer->current_state == state_end))
	{
		new_elem = ft_lstnew(eoi_token(), sizeof(t_token));
		LST_ADDCREATE(token_list, new_elem);
		return (token_list);
	}
	ft_lstdel(&token_list, delete_token);
	return (NULL);
}
