/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:05:03 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 14:37:19 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsm.h"

t_fsm		*init_fsm(void)
{
	static t_fsm_state	states[] = {
		{ false, { 1, 2, 3, 4, -1 } },
		{ true, { 1, -1, -1, -1 } },
		{ true, { -1, 2, -1, -1 } },
		{ true, { -1, -1, -1, -1 } },
		{ true, { -1, -1, -1, 4 } },
	};
	static t_fsm			fsm = { .states = states };

	fsm.start = fsm.states[0];
	fsm.current = fsm.states[0];
	return (&fsm);
}
