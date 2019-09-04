/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:52:52 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/02 19:00:36 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_5(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type == dollar)
	{
		l->current_state = state_expansion;
		return (RULE_ADD_ATOM | RULE_MOVE_ATOM);
	}
	return (RULE_NO_APPLY);
}
