/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 07:43:59 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 08:08:42 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "memory.h"

#include "multiline.h"

bool							multiline_remove_line(t_multiline *m, int idx)
{
	if (idx >= m->count)
		return (false);
	string_destroy(m->lanes[m->count], false);
	ft_memmove(m->lanes + idx, m->lanes + idx + 1,
		sizeof(t_string *) * m->count - idx);
	return (true);
}
