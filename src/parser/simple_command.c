/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:00:53 by batman            #+#    #+#             */
/*   Updated: 2019/08/22 14:51:04 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

t_btree_node		*simple_command(void)
{
	t_btree_node		*node;

	node = save_curr_token_wrapper(simple_command1);
	if (!node)
		node = save_curr_token_wrapper(simple_command2);
	return (node);
}

t_btree_node		*simple_command1(void)
{
	t_btree_node		*cmd_word_node;
	t_btree_node		*cmd_suffix_node;

	cmd_word_node = save_curr_token_wrapper(cmd_word);
	if (!cmd_word_node)
		return (NULL);
	// todo: difference between suffix and word
	cmd_suffix_node = save_curr_token_wrapper(cmd_word);
	cmd_word_node->right = cmd_suffix_node;
	return (cmd_word_node);
}

t_btree_node		*simple_command2(void)
{
	t_btree_node	*node;

	node = save_curr_token_wrapper(cmd_word);
	return (node);
}
