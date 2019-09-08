/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:34:18 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/08 03:42:22 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

static t_btree_node		*io_redirect_in(void)
{
	t_btree_node		*filename_node;

	if (!assert_token_type(token_op, ">"))
		return (NULL);
	g_current_token_list = g_current_token_list->next;
	if (!assert_token_type(token_word, NULL))
		return (NULL);
	filename_node = create_node_from_current_token(true, ast_redirect_out);
	return (filename_node);
}

static t_btree_node		*cmd_suffix1(void)
{
	t_btree_node		*cmd_word_node;

	cmd_word_node = save_curr_token_wrapper(cmd_word);
	if (!cmd_word_node)
		return (cmd_word_node);
	cmd_word_node->right = save_curr_token_wrapper(cmd_word);
	return (cmd_word_node);
}

static t_btree_node		*cmd_suffix2(void)
{
	return (save_curr_token_wrapper(io_redirect_in));
}

t_btree_node			*cmd_suffix(void)
{
	t_btree_node		*word_node;
	t_btree_node		*io_file_node;

	word_node = cmd_suffix1();
	io_file_node = cmd_suffix2();
	if (io_file_node)
	{
		io_file_node->right = word_node;
		return (io_file_node);
	}
	return (word_node);
}