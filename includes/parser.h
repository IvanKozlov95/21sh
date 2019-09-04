/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:38:43 by batman            #+#    #+#             */
/*   Updated: 2019/09/01 16:43:2 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "lexer.h"
#include "btree.h"

extern t_list				*g_current_token_list;

struct						s_astnode
{
	char			*value;
};
typedef struct s_astnode	t_astnode;

/*
**	program
*/
t_btree_node		*program(void);

/*
**	complete_command
*/
t_btree_node		*complete_command(void);
t_btree_node		*complete_command1(void);
t_btree_node		*complete_command2(void);
t_btree_node		*complete_command3(void);

/*
**	list
*/
t_btree_node		*list(void);

/*
**	pipeline
*/
t_btree_node		*pipeline(void);
t_btree_node		*pipeline1(void);
t_btree_node		*pipeline2(void);

/*
**	simple_command
*/
t_btree_node		*simple_command(void);
t_btree_node		*simple_command1(void);
t_btree_node		*simple_command2(void);

/*
**	cmd_word
*/
t_btree_node		*cmd_word(void);

/*
**	set_op
*/
bool				sep_op(void);

/*
**	helpers
*/
t_token				*curr_token(void);
bool				assert_token_type(t_token_type expected_type,
	const char expected_value[]);
t_btree_node		*create_node_from_current_token(void);
t_btree_node		*save_curr_token_wrapper(t_btree_node *(f)(void));

/*
**	parse
*/
t_btree_node		*parse(t_list *tokenlist);

/*
**	ast
*/
t_astnode			*create_ast_node(char *value);
void				delete_ast_node(void *node, size_t size);

#endif
