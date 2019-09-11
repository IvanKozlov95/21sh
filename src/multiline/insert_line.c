/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 07:39:11 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 08:08:42 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "memory.h"

#include "multiline.h"

bool							multiline_apped_line(t_multiline *m)
{
	if (m->count + 1 == m->size)
	{
		m->lanes = realloc(m->lanes, m->size * 2);
		if (!m->lanes)
			return (false);
		m->size *= 2;
	}
	m->lanes[m->count] = string_init(0);
	m->count++;
	return (true);
}
