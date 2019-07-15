/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:42:57 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/15 13:57:34 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "list.h"

enum						e_fsm_state
{
	fsm_start = 0,
	fsm_general,
	fsm_inquote,
	fsm_special,
	fsm_error,
	fsm_end,
	fsm_states_count,
};
typedef enum e_fsm_state	t_fsm_state;

enum						e_atom_type
{
	unkn = -1,
	gnrl = 0,
	ppipe,
	apsd,
	quote,
	dquote,
	bquote,
	smcln,
	whitespc,
	ttab,
	nl,
	gt,
	ls,
	eos,
	atom_type_count
};
typedef enum e_atom_type	t_atom_type;

struct						s_token
{
	t_atom_type				type;
	char					*value;
};
typedef struct s_token		t_token;

struct						s_lexer
{
	t_fsm_state				current_state;
	char					*input;
	t_atom_type				quote_type;
	t_atom_type				special_type;
};
typedef struct s_lexer		t_lexer;

/*
**	src/lexer/init.c
*/
t_lexer						*init_lexer(char *input);

/*
**	src/lexer/next.c
*/
t_token						*next_token(t_lexer *lexer);

/*
**	src/lexer/token.c
*/
t_token						*create_token(t_lexer *l, char *value);

/*
**	src/lexer/switch.c
*/
void						switch_state(t_lexer *l, t_atom_type curr_atom);

/*
**	src/lexer/main.c
*/
t_list						*get_token_list(t_lexer *lexer);

#endif
