/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 07:48:14 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 18:03:04 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "memory.h"

#include "multiline.h"

bool							multiline_instert_at(t_multiline *m, int line,
	int pos, char *add)
{
	if (line > m->count)
		return (false);
	if (line == m->count && !multiline_apped_line(m))
		return (false);
	return (string_insert(m->lanes[line], add, pos));
}
