/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:34:18 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/08 11:33:19 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"



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
	t_btree_node		*suffix_node;

	suffix_node = NULL;
	suffix_node = save_curr_token_wrapper(io_redirect_out);
	if (!suffix_node)
		suffix_node = save_curr_token_wrapper(io_redirect_in);
	return (suffix_node);
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
