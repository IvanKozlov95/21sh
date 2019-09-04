/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule7_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:53:51 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/03 00:21:36 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_7_8(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type == nl || cur_atom_type == blank)
	{
		if (l->current_state != state_start)
			l->current_state = state_end;
		return (RULE_MOVE_ATOM);
	}
	return (RULE_NO_APPLY);
}
