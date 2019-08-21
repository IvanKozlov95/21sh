/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:28:21 by batman            #+#    #+#             */
/*   Updated: 2019/08/22 14:52:30 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
#include "parser.h"

t_btree_node		*list(void)
{
	t_btree_node	*node;

	node = save_curr_token_wrapper(pipeline);
	return (node);
}
