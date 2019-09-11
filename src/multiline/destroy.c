/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:24:56 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 22:05:02 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

#include "multiline.h"

void			multiline_destroy(t_multiline *m)
{
	size_t		i;

	i = -1;
	while (++i < m->count)
		string_destroy(m->lanes[i], false);
	ft_free(2, m->lanes, m);
}