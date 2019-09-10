/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:52:52 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 03:21:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_6(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type != gnrl && cur_atom_type != blank)
	{
		if (l->current_state == state_word)
		{
			l->current_state = state_delim_token;
			return (RULE_NO_ACTION);
		}
		l->current_state = state_op;
		l->op_type = cur_atom_type;
		return (RULE_ADD_ATOM | RULE_MOVE_ATOM);
	}
	return (RULE_NO_APPLY);
}
