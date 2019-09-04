/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule2_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:07:17 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/03 19:28:04 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_2_3(t_lexer *l, t_atom_type cur_atom_type)
{
	if (l->current_state == state_op)
	{
		if (l->op_type == cur_atom_type)
			return (RULE_ADD_ATOM | RULE_MOVE_ATOM);
		else
			return (RULE_END_TOKEN | RULE_ADD_ATOM | RULE_ADD_ATOM);
	}
	return (RULE_NO_APPLY);
}
