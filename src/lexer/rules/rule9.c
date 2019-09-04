/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:53:51 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/03 00:23:28 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_9(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type == gnrl && l->current_state == state_word)
	{
		return (RULE_ADD_ATOM | RULE_MOVE_ATOM);
	}
	return (RULE_NO_APPLY);
}
