/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:38:36 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/15 14:06:06 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "lexer.h"
#include "memory.h"
#include "dstring.h"

static t_atom_type		get_atom_type(int ch)
{
	static bool				initialized = false;
	static t_atom_type		ascii_lookup[128] = { gnrl };

	if (!initialized)
	{
		ascii_lookup['\0'] = eos;
		ascii_lookup['|'] = ppipe;
		ascii_lookup['&'] = apsd;
		ascii_lookup['\''] = quote;
		ascii_lookup['"'] = dquote;
		ascii_lookup['`'] = bquote;
		ascii_lookup[';'] = smcln;
		ascii_lookup[' '] = whitespc;
		ascii_lookup['\t'] = ttab;
		ascii_lookup['\n'] = nl;
		ascii_lookup['<'] = ls;
		ascii_lookup['>'] = gt;
		initialized = true;
	}
	return (ascii_lookup[ch]);
}

static bool		is_valid_atom(int atom)
{
	t_atom_type		type;

	type = get_atom_type(atom);
	if (type == unkn)
		set_error(error_unkn_atom, SH_PREFIX"Unexpected symbol '%c'\n", atom);
	return (type != unkn);
}

static bool		should_add_atom(t_lexer *l, t_atom_type curr_atom)
{
	if (l->quote_type != unkn)
		return (curr_atom == l->quote_type ? false : true);
	return (curr_atom != whitespc && curr_atom != ttab);
}

static char		*build_lexeme(t_lexer *lexer)
{
	bool			done;
	bool			valid;
	t_string		*lexeme;
	t_atom_type		curr_atom_type;

	done = false;
	valid = true;
	lexeme = string_init(0);
	while (lexer->current_state != fsm_end && lexer->current_state != fsm_error
		&& lexer->input)
	{
		curr_atom_type = get_atom_type(*lexer->input);
		if (curr_atom_type == unkn)
			set_error(error_unkn_atom, SH_PREFIX"Unexpected symbol '%c'\n",
				*lexer->input);
		switch_state(lexer, curr_atom_type);
		if (should_add_atom(lexer, curr_atom_type))
			string_appendn(lexeme, lexer->input, 1);
		lexer->input++;
	}
	return (string_destroy(lexeme, lexer->current_state != fsm_error));
}

t_token		*next_token(t_lexer *lexer)
{
	char		*token_value;

	if (*lexer->input == '\0')
		return (NULL);
	lexer->current_state = fsm_start;
	lexer->quote_type = unkn;
	lexer->special_type = unkn;
	token_value = build_lexeme(lexer);
	if (!token_value)
		return (NULL);
	return (create_token(lexer, token_value));
}
