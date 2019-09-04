/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:53:51 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/03 00:29:17 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_1(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type == eos)
	{
		l->current_state = state_end;
		return (RULE_NO_ACTION);
	}
	return (RULE_NO_APPLY);
}
