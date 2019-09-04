/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:03:32 by batman            #+#    #+#             */
/*   Updated: 2019/09/02 23:59:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_token		*g_l;
t_list		*g_current_token_list;

bool				assert_token_type(t_token_type expected_type,
	const char expected_value[])
{
	bool		type_macth;
	bool		value_match;

	if (g_current_token_list == NULL)
		return (false);
	type_macth = curr_token()->type == expected_type;
	value_match = expected_value
		? ft_strequ(curr_token()->value, expected_value) : true;
	return (type_macth && value_match);
}

t_token				*curr_token(void)
{
	if (g_current_token_list == NULL)
		return (NULL);
	return (g_current_token_list->content);
}

t_btree_node		*create_node_from_current_token(void)
{
	t_btree_node	*node;
	t_token			*token;
	t_astnode		*astnode;

	node = NULL;
	token = curr_token();
	if (token)
	{
		astnode = create_ast_node(token->value);
		node = new_btree_node(astnode, sizeof(t_astnode));
		g_current_token_list = g_current_token_list->next;
	}
	return (node);
}

t_btree_node		*save_curr_token_wrapper(t_btree_node *(f)(void))
{
	t_list			*save;
	t_btree_node	*result;

	save = g_current_token_list;
	result = f();
	if (!result)
		g_current_token_list = save;
	return (result);
}
