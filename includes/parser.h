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

# include "lexer.h"
# include "btree.h"

/*
**	Converts t_btree node's content to t_astnode pointer
**	and makes my life a bit easier :)
*/

# define GETAST(n) ((t_astnode *)((n)->content))

extern t_list				*g_current_token_list;

enum						e_astnode_type
{
	ast_cmd = 0,
	ast_pipe,
};

typedef enum e_astnode_type	t_astnode_type;

struct						s_astnode
{
	t_astnode_type	type;
	char			*value;
};
typedef struct s_astnode	t_astnode;

typedef char				*(*t_expantion)(char **);

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
t_btree_node		*create_node_from_current_token(bool expand,
	t_astnode_type type);
t_btree_node		*save_curr_token_wrapper(t_btree_node *(f)(void));

/*
**	parse
*/
t_btree_node		*parse(t_list *tokenlist);

/*
**	parser/expantions
*/
char				*expand_token(char *token);
char				*apply_expantion(char **token_ptr, t_expantion expantions[],
	bool (*stop_condition)(char c));
char				*argument_expantion(char **token_ptr);
char				*double_quote_expantion(char **quote_ptr);
char				*single_quote_expantion(char **quoute_ptr);

/*
**	ast
*/
t_astnode			*create_ast_node(char *value, t_astnode_type type);
void				delete_ast_node(void *node, size_t size);

#endif
