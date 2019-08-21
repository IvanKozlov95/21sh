/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:11:03 by batman            #+#    #+#             */
/*   Updated: 2019/08/22 15:11:26 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list		*g_current_token_list;

t_btree_node		*parse(t_list *tokenlist)
{
	t_btree_node		*ast_tree;

	g_current_token_list = tokenlist;
	ast_tree = program();
	ft_lstdel(&tokenlist, delete_token);
	return (ast_tree);
}
