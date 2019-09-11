/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_char_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:55:25 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/11 16:21:30 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "memory.h"

#include "multiline.h"

char					*multiline_to_char_ptr(t_multiline *m)
{
	size_t		i;
	t_string	*s;

	i = -1;
	s = string_init(0);
	while (++i < m->count)
	{
		if (s->length > 0)
			string_append(s, "\n");
		string_append(s, m->lanes[i]->content);
	}
	return (string_destroy(s, true));
}
