/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule2_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:07:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/08 17:09:35 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static bool		can_form_an_operator(t_lexer *l, t_atom_type cur_atom_type)
{
	if (l->op_type == cur_atom_type)
		return (cur_atom_type == gt || cur_atom_type == ls);
	return (false);
}

int				rule_2_3(t_lexer *l, t_atom_type cur_atom_type)
{
	if (l->current_state == state_op)
	{
		l->current_state = state_delim_token;
		if (can_form_an_operator(l, cur_atom_type))
			return (RULE_ADD_ATOM | RULE_MOVE_ATOM);
		return (RULE_NO_ACTION);
	}
	return (RULE_NO_APPLY);
}
