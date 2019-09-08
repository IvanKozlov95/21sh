/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 11:33:01 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/08 11:40:16 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

static t_btree_node		*io_redirect_out1(void)
{
	if (!assert_token_type(token_op, ">"))
		return (NULL);
	g_current_token_list = g_current_token_list->next;
	if (!assert_token_type(token_word, NULL))
		return (NULL);
	return (create_node_from_current_token(true, ast_redirect_out));
}

static t_btree_node		*io_redirect_out2(void)
{
	if (!assert_token_type(token_op, ">>"))
		return (NULL);
	g_current_token_list = g_current_token_list->next;
	if (!assert_token_type(token_word, NULL))
		return (NULL);
	return (create_node_from_current_token(true, ast_redirect_out_save_content));
}

t_btree_node			*io_redirect_out(void)
{
	t_btree_node		*redirect_node;

	redirect_node = save_curr_token_wrapper(io_redirect_out1);
	if (!redirect_node)
		redirect_node = save_curr_token_wrapper(io_redirect_out2);
	return (redirect_node);
}

t_btree_node			*io_redirect_in(void)
{
	t_btree_node		*filename_node;

	if (!assert_token_type(token_op, "<"))
		return (NULL);
	g_current_token_list = g_current_token_list->next;
	if (!assert_token_type(token_word, NULL))
		return (NULL);
	filename_node = create_node_from_current_token(true, ast_redirect_in);
	return (filename_node);
}
