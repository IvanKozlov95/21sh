/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:30:28 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/15 13:54:47 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "memory.h"

t_token		*create_token(t_lexer *l, char *value)
{
	t_token		*ret;

	ret = ft_memalloc(sizeof(t_token));
	ret->value = value;
	ret->type = gnrl;
	if (l->quote_type != unkn)
		ret->type = l->quote_type;
	if (l->special_type != unkn)
		ret->type = l->special_type;
	return (ret);
}
