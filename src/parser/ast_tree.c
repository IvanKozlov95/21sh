/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:19:59 by batman            #+#    #+#             */
/*   Updated: 2019/09/06 05:37:09 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "memory.h"
#include "ftstring.h"

t_astnode	*create_ast_node(char *value, t_astnode_type type)
{
	t_astnode		*node;

	node = ft_memalloc(sizeof(t_astnode));
	node->value = ft_strdup(value);
	node->type = type;
	return (node);
}

void		delete_ast_node(void *node, size_t size)
{
	t_astnode	*astnode;

	(void)size;
	astnode = (t_astnode *)node;
	ft_free(1, astnode->value, node);
}
