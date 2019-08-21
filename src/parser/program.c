/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:49:41 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/22 15:11:29 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include "ftstring.h"

t_token		*g_l;
t_list		*g_current_token_list;

t_btree_node		*program(void)
{
	return (complete_command());
}
