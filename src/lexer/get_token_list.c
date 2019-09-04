/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:37:49 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/02 23:52:18 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "memory.h"

t_list		*get_token_list(t_lexer *lexer)
{
	t_token			*tkn;
	t_list			*new_elem;
	t_list			*token_list;
	t_token_type	token_type;

	token_list = NULL;
	while ((tkn = recognize_token(lexer)))
	{
		new_elem = ft_lstnew(tkn, sizeof(t_token));
		LST_ADDCREATE(token_list, new_elem);
		token_type = tkn->type;
		ft_free(1, tkn);
		if (token_type == token_eoi)
			break ;
	}
	return (token_list);
}
