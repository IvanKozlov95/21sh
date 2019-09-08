/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:00:53 by batman            #+#    #+#             */
/*   Updated: 2019/09/08 03:54:33 by ikozlov          ###   ########.fr       */
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
	cmd_suffix_node = save_curr_token_wrapper(cmd_suffix);
	cmd_word_node->right = cmd_suffix_node;
	return (cmd_word_node);
}

t_btree_node		*simple_command2(void)
{
	t_btree_node	*node;

	node = save_curr_token_wrapper(cmd_word);
	return (node);
}
