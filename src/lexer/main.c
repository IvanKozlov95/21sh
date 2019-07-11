/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 17:37:49 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/14 17:43:41 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "lexer.h"
#include "memory.h"

t_list		*get_token_list(t_lexer *lexer)
{
	t_token		*tkn;
	t_list		*new_elem;
	t_list		*token_list;

	token_list = NULL;
	while ((tkn = next_token(lexer)))
	{
		new_elem = ft_lstnew(tkn, sizeof(t_token));
		LST_ADDCREATE(token_list, new_elem);
		ft_free(1, tkn);
	}
	return (token_list);
}
