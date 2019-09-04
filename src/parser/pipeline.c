/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:50:12 by batman            #+#    #+#             */
/*   Updated: 2019/09/03 00:00:19 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

t_btree_node		*pipeline(void)
{
	t_btree_node	*node;

	node = save_curr_token_wrapper(pipeline1);
	if (!node)
		node = save_curr_token_wrapper(pipeline2);
	return (node);
}

t_btree_node		*pipeline1(void)
{
	t_btree_node	*node;
	t_btree_node	*simple_command_node1;
	t_btree_node	*simple_command_node2;

	simple_command_node1 = save_curr_token_wrapper(simple_command);
	if (!simple_command_node1)
		return (NULL);
	if (!assert_token_type(token_op, "|") ||
		(simple_command_node2 = save_curr_token_wrapper(simple_command)) == NULL)
	{
		free_node(simple_command_node1, delete_ast_node);
		return (NULL);
	}
	node = new_btree_node(NULL, 0);
	node->left = simple_command_node1;
	node->right = simple_command_node2;
	return (node);
}

t_btree_node		*pipeline2(void)
{
	t_btree_node	*node;

	node = save_curr_token_wrapper(simple_command);
	return (node);
}
