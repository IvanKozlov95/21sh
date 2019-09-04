/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:32:53 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/03 00:03:02 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

#include "parser.h"

bool		sep_op(void)
{
	if (assert_token_type(token_op, ";"))
	{
		g_current_token_list = g_current_token_list->next;
		return (true);
	}
	return (false);
}
