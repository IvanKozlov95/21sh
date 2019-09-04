/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:19:20 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/02 19:20:34 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_10(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type == hash)
	{
		l->current_state = state_comment;
		return (RULE_ADD_ATOM | RULE_MOVE_ATOM);
	}
	return (RULE_NO_APPLY);
}
