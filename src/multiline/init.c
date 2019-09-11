/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 07:31:07 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/11 16:21:19 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "memory.h"
#include "ftstring.h"

#include "multiline.h"

t_multiline						*multiline_init_from_char_ptr(char *ptr)
{
	char				*nl;
	t_multiline			*result;

	result = multiline_init(10);
	while ((nl = ft_strchr(ptr, '\n')))
	{
		*nl = '\0';
		multiline_instert_at(result, result->count, 0, ptr);
		ptr = nl + 1;
	}
	if (ptr)
		multiline_instert_at(result, result->count, 0, ptr);
	return (result);
}

t_multiline						*multiline_init(size_t size)
{
	t_multiline			*result;

	result = ft_memalloc(sizeof(t_multiline) * size);
	result->size = size;
	result->lanes = ft_memalloc(sizeof(t_string *) * size);
	return (result);
}
