/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:57:08 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 05:33:54 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

#include "21sh.h"
#include "lexer.h"
#include "parser.h"

static bool		single_quote_stop_condtion(char current)
{
	return (current == '\'');
}

char	*single_quote_expantion(char **qoute_ptr)
{
	static t_expantion		quote_expantions[] = {
		NULL, NULL, double_quote_expantion, NULL,
		argument_expantion, NULL,
	};

	(*qoute_ptr)++;
	return (apply_expantion(qoute_ptr,
		quote_expantions, single_quote_stop_condtion));
}

static bool		double_quote_stop_condtion(char current)
{
	return (current == '"');
}

char			*double_quote_expantion(char **quote_ptr)
{
	static t_expantion		quote_expantions[] = {
		NULL, &single_quote_expantion, NULL, NULL,
		argument_expantion, NULL,
	};

	(*quote_ptr)++;
	return (apply_expantion(quote_ptr,
		quote_expantions, double_quote_stop_condtion));
}
