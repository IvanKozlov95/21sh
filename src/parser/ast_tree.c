/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:19:59 by batman            #+#    #+#             */
/*   Updated: 2019/08/22 14:49:27 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "memory.h"
#include "ftstring.h"

t_astnode	*create_ast_node(char *value)
{
	t_astnode		*node;

	node = ft_memalloc(sizeof(t_astnode));
	node->value = ft_strdup(value);
	return (node);
}

void		delete_ast_node(void *node, size_t size)
{
	t_astnode	*astnode;

	(void)size;
	astnode = (t_astnode *)node;
	ft_free(1, astnode->value, node);
}
