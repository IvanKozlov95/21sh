/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:53:51 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 04:57:37 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		rule_1(t_lexer *l, t_atom_type cur_atom_type)
{
	if (cur_atom_type == eos)
	{
		if (l->current_state != state_quote
			&& l->current_state != state_expansion)
			l->current_state = l->lexeme->length > 0
				? state_delim_token : state_end;
		else
			return (RULE_END_INPUT);
		return (RULE_NO_ACTION);
	}
	return (RULE_NO_APPLY);
}
