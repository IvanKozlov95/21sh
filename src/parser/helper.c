/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:03:32 by batman            #+#    #+#             */
/*   Updated: 2019/09/04 12:59:47 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

#include "21sh.h"
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
	char			*expanded_token;

	node = NULL;
	token = curr_token();
	if (token)
	{
		expanded_token = expand_token(token->value);
		debug("token |%s| - expanded |%s|\n", token->value, expanded_token);
		astnode = create_ast_node(expanded_token);
		node = new_btree_node(astnode, sizeof(t_astnode));
		g_current_token_list = g_current_token_list->next;
		ft_free(1, expanded_token);
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
