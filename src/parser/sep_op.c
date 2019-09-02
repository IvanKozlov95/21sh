/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sep_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:32:53 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/01 18:18:42 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool		sep_op(void)
{
	if (assert_token_type(smcln))
	{
		g_current_token_list = g_current_token_list->next;
		return (true);
	}
	return (false);
}
