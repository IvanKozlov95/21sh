/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:37:42 by ikozlov           #+#    #+#             */
/*   Updated: 2019/11/05 20:28:18 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_btree_node		*complete_command(void)
{
	t_btree_node	*node;

	node = NULL;
	if ((node = save_curr_token_wrapper(complete_command1)) != NULL)
		return (node);
	if ((node = save_curr_token_wrapper(complete_command2)) != NULL)
		return (node);
	if ((node = save_curr_token_wrapper(complete_command3)) != NULL)
		return (node);
	return (node);
}

t_btree_node		*complete_command1(void)
{
	t_btree_node	*node;
	t_btree_node	*list_node;
	t_btree_node	*complete_command_node;

	list_node = save_curr_token_wrapper(list);
	if (!list_node)
		return (NULL);
	if (!sep_op())
	{
		free_node(list_node, delete_ast_node);
		return (NULL);
	}
	complete_command_node = save_curr_token_wrapper(complete_command);
	if (!complete_command_node)
	{
		free_node(list_node, delete_ast_node);
		return (NULL);
	}
	node = list_node;
	node->left = complete_command_node;
	return (node);
}

t_btree_node		*complete_command2(void)
{
	t_btree_node	*node;
	t_btree_node	*list_node;

	list_node = save_curr_token_wrapper(list);
	if (!list_node)
		return (NULL);
	// todo: other separator ops
	if (!sep_op())
	{
		free_node(list_node, delete_ast_node);
		return (NULL);
	}
	node = list_node;
	return (node);
}

t_btree_node		*complete_command3(void)
{
	t_btree_node	*node;

	node = save_curr_token_wrapper(list);
	return (node);
}
