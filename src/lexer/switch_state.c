/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:10:30 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/23 16:21:59 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "lexer.h"

static void		switch_special_state(t_lexer *l, t_atom_type curr_atom)
{
	if ((l->special_type == gt || l->special_type == ls)
		&& l->special_type != curr_atom)
		l->current_state = fsm_special;
	else
		l->current_state = fsm_end;
}

static void		swtich_inquote_state(t_lexer *l, t_atom_type curr_atom)
{
	if (l->quote_type == curr_atom)
		l->current_state = fsm_end;
}

static void		switch_general_state(t_lexer *l, t_atom_type curr_atom)
{
	if (curr_atom == whitespc || curr_atom != gnrl)
		l->current_state = fsm_end;
}

static void		switch_start_state(t_lexer *l, t_atom_type curr_atom)
{
	if (curr_atom == whitespc || curr_atom == ttab)
		return ;
	if (curr_atom == quote || curr_atom == dquote
		|| curr_atom == bquote)
	{
		l->quote_type = curr_atom;
		l->current_state = fsm_inquote;
	}
	else if (curr_atom == gnrl)
		l->current_state = fsm_general;
	else if (curr_atom == whitespc)
		l->current_state = fsm_end;
	else if (curr_atom != gnrl)
	{
		l->special_type = curr_atom;
		l->current_state = fsm_special;
	}
}

void			switch_state(t_lexer *l, t_atom_type curr_atom)
{
	if (curr_atom == unkn)
	{
		set_error(error_unkn_atom, "Unexpected symbol '%c'\n",
			*l->input);
		l->current_state = fsm_error;
	}
	else if (l->current_state == fsm_start)
		switch_start_state(l, curr_atom);
	else if (l->current_state == fsm_general)
		switch_general_state(l, curr_atom);
	else if (l->current_state == fsm_inquote)
		swtich_inquote_state(l, curr_atom);
	else if (l->current_state == fsm_special)
		switch_special_state(l, curr_atom);
}
