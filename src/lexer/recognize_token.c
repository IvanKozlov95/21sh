/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognize_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:14:28 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/04 01:48:26 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "dstring.h"

#include "21sh.h"
#include "lexer.h"

static t_atom_type		get_atom_type(int ch)
{
	static bool				initialized = false;
	static t_atom_type		ascii_lookup[128] = { gnrl };

	if (!initialized)
	{
		ascii_lookup['\0'] = eos;
		ascii_lookup['$'] = dollar;
		ascii_lookup['|'] = ppipe;
		ascii_lookup['&'] = apsd;
		ascii_lookup['\''] = quote;
		ascii_lookup['"'] = dquote;
		ascii_lookup['`'] = bquote;
		ascii_lookup[';'] = smcln;
		ascii_lookup[' '] = blank;
		ascii_lookup['\t'] = blank;
		ascii_lookup['\r'] = blank;
		ascii_lookup['\n'] = nl;
		ascii_lookup['<'] = ls;
		ascii_lookup['>'] = gt;
		ascii_lookup['#'] = hash;
		initialized = true;
	}
	return (ascii_lookup[ch]);
}

static int				apply_rules(t_lexer *lexer, t_atom_type cur_atom_type)
{
	int						i;
	int						result;
	static t_lexer_rule		rules[] = {
		rule_1, rule_2_3, rule_4, rule_5,
		rule_6, rule_7_8, rule_9, rule_10,
		rule_11, NULL
	};

	i = -1;
	result = 0;
	while (rules[++i])
	{
		result = rules[i](lexer, cur_atom_type);
		if (result != 0)
			return (result);
	}
	return (result);
}

static t_token			*eoi_token(void)
{
	t_token		*eoi_token;

	eoi_token = ft_memalloc(sizeof(t_token));
	eoi_token->type = token_eoi;
	return (eoi_token);
}

t_token					*recognize_token(t_lexer *lexer)
{
	t_string		*lexeme;
	int				rules_response;

	if (!lexer->input)
		return (NULL);
	lexeme = string_init(0);
	lexer_default_state(lexer);
	while (lexer->current_state != state_end)
	{
		rules_response = apply_rules(lexer, get_atom_type(*lexer->input));
		if (rules_response & RULE_ADD_ATOM)
			string_appendn(lexeme, lexer->input, 1);
		if (rules_response & RULE_MOVE_ATOM)
			lexer->input++;
		if (rules_response & RULE_END_TOKEN && lexeme->length > 0)
			break ;
		if (rules_response == 0)
		{
			debug("Unexpected atom %c\n", *lexer->input);
			break ;
		}
	}
	return (lexeme->length == 0 ? eoi_token()
		: create_token(lexer, string_destroy(lexeme, true)));
}
