/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:35:23 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 19:53:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

#include "multiline.h"

void		multiline_debug(t_multiline *m)
{
	size_t		i;

	i = -1;
	while (++i < m->count)
		debug("#%d |%s|\n", i, m->lanes[i]->content);
	debug("combined:\n|%s|\n", multiline_to_char_ptr(m));
}