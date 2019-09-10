/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:42:57 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/10 05:07:25 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "list.h"
# include "dstring.h"

# define RULE_NO_APPLY 0
# define RULE_ADD_ATOM 1
# define RULE_MOVE_ATOM 1 << 1
# define RULE_END_INPUT 1 << 2
# define RULE_NO_ACTION 1 << 3

enum						e_fsm_state
{
	state_start = 0,
	state_op,
	state_word,
	state_quote,
	state_comment,
	state_expansion,
	state_delim_token,
	state_end,
	state_error,
	fsm_states_count,
};
typedef enum e_fsm_state	t_fsm_state;

enum						e_atom_type
{
	unkn = -1,
	gnrl = 0,
	squote,
	dquote,
	blank,
	dollar,
	apsd,
	hash,
	ppipe,
	bquote,
	smcln,
	nl,
	gt,
	ls,
	eos,
	atom_type_count
};
typedef enum e_atom_type	t_atom_type;

enum						e_token_type
{
	token_unkn = -1,
	token_word,
	token_op,
	token_eoi
};
typedef enum e_token_type	t_token_type;

# define IS_EOI_TOKEN(l) ((l) && ((t_token *)(l)->content)->type != token_eoi)

struct						s_token
{
	t_token_type			type;
	char					*value;
};
typedef struct s_token		t_token;

struct						s_lexer
{
	t_fsm_state				current_state;
	char					*input;
	t_string				*lexeme;
	t_atom_type				quote_type;
	t_atom_type				op_type;
};
typedef struct s_lexer		t_lexer;

typedef int					(*t_lexer_rule)(t_lexer *, t_atom_type);

/*
**	src/lexer/init.c
*/

t_lexer						*init_lexer(void);
void						lexer_default_state(t_lexer *lexer);
void						lexer_default_state_step(t_lexer *lexer);

/*
**	src/lexer/token.c
*/

t_token						*create_token(t_lexer *l, char *value);
void						delete_token(void *token_list, size_t size);

/*
**	src/lexer/main.c
*/

t_list						*get_token_list(t_lexer *lexer, t_list **tokens);

/*
**	src/lexer/recognize_token.c
*/

t_atom_type					get_atom_type(int ch);
t_token						*recognize_token(t_lexer *lexer);

/*
**	Lexer rules
**	src/lexer/rules/
*/
int							rule_1(t_lexer *l, t_atom_type cur_atom_type);
int							rule_2_3(t_lexer *l, t_atom_type cur_atom_type);
int							rule_4(t_lexer *l, t_atom_type cur_atom_type);
int							rule_5(t_lexer *l, t_atom_type cur_atom_type);
int							rule_6(t_lexer *l, t_atom_type cur_atom_type);
int							rule_7_8(t_lexer *l, t_atom_type cur_atom_type);
int							rule_9(t_lexer *l, t_atom_type cur_atom_type);
int							rule_10(t_lexer *l, t_atom_type cur_atom_type);
int							rule_11(t_lexer *l, t_atom_type cur_atom_type);

#endif
