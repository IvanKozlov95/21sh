/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:38:36 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 16:23:14 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "lexer.h"
#include "memory.h"
#include "dstring.h"

static t_atom_type		get_atom_type(int ch)
{
	static t_atom_type		ascii_type_lookup_table[] = {
		eos, unkn, unkn, unkn, unkn, unkn, unkn, unkn,
		unkn, whitespc, unkn, unkn, unkn, unkn, unkn, unkn,
		unkn, unkn, unkn, unkn, unkn, unkn, unkn, unkn,
		unkn, unkn, unkn, unkn, unkn, unkn, unkn, unkn,
		whitespc, unkn, nonterm, unkn, nonterm, unkn, nonterm, nonterm,
		nonterm, nonterm, unkn, unkn, unkn, term, unkn, term,
		term, term, term, term, term, term, term, term,
		unkn, unkn, unkn, unkn, double_nonterm, unkn, double_nonterm, unkn,
		unkn, term, term, term, term, term, term, term,
		term, term, term, term, term, term, term, term,
		term, term, term, term, term, term, term, term,
		term, term, term, unkn, unkn, unkn, unkn, term,
		nonterm, term, term, term, term, term, term, term,
		term, term, term, term, term, term, term, term,
		term, term, term, term, term, term, term, term,
		term, term, term, nonterm, nonterm, nonterm, unkn, unkn,
	};

	return (ascii_type_lookup_table[ch]);
}

static bool		step(t_fsm *fsm, int ch)
{
	int				next_state_idx;
	t_atom_type		atom_type;

	atom_type = get_atom_type(ch);
	next_state_idx = fsm->current.out[atom_type];
	if (next_state_idx != -1)
		fsm->current = fsm->states[next_state_idx];
	return (next_state_idx == -1);
}

static bool		is_valid_atom(int atom)
{
	t_atom_type		type;

	type = get_atom_type(atom);
	if (type == unkn)
		set_error(error_unkn_atom, SH_PREFIX"Unexpected symbol '%c'\n", atom);
	return (type != unkn);
}

t_token		*next_token(t_lexer *lexer)
{
	t_token		*ret;
	t_string	*lexeme;
	bool		done;
	bool		valid;

	done = false;
	valid = true;
	if (*lexer->input == '\0')
		return (NULL);
	lexeme = string_init(0);
	ret = ft_memalloc(sizeof(t_token));
	while (!done && valid)
	{
		valid = is_valid_atom(*lexer->input);
		if (valid)
		{
			done = step(lexer->fsm, *lexer->input);
			if (!done && valid)
				string_appendn(lexeme, lexer->input, 1);
		}
		lexer->input += !done || !valid;
	}
	if (done)
		ret->value = string_destroy(lexeme, true);
	// todo:fix leak
	lexer->fsm->current = lexer->fsm->start;
	return (ret);
}
