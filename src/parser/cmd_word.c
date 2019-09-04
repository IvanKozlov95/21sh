/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:13:40 by batman            #+#    #+#             */
/*   Updated: 2019/09/02 23:59:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

t_btree_node		*cmd_word(void)
{
	t_btree_node		*node;

	if (!assert_token_type(token_word, NULL))
		return (NULL);
	node = create_node_from_current_token();
	return (node);
}
