/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:04:55 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/04 13:34:28 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

#include "21sh.h"
#include "lexer.h"
#include "parser.h"

static bool		stop_conditon(char current)
{
	return (current == ' ' || current == '\t');
}

char	*argument_expantion(char **token_ptr)
{
	char					*arg_name;
	char					*arg_value;
	static t_expantion		quote_expantions[] = {
		NULL, single_quote_expantion, double_quote_expantion, NULL,
		NULL,
	};

	(*token_ptr)++;
	arg_name = apply_expantion(token_ptr,
		quote_expantions, stop_conditon);
	arg_value = dict_find(g_env, arg_name, true);
	return (arg_value);
}
