/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:13:40 by batman            #+#    #+#             */
/*   Updated: 2019/08/22 14:43:55 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

t_btree_node		*cmd_word(void)
{
	t_btree_node		*node;

	if (!assert_token_type(gnrl))
		return (NULL);
	node = create_node_from_current_token();
	return (node);
}
