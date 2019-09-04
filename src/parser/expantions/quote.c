/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 01:57:08 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/04 05:04:33 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"

#include "21sh.h"
#include "lexer.h"
#include "parser.h"

char	*single_quote_expantion(char **quoute_ptr)
{
	fatal(EXIT_SIGNAL, "signle quote expantion is not implemented yet\n");
	return (NULL);
}

static bool		double_quote_stop_condtion(char current)
{
	return (current == '"');
}

char			*double_quote_expantion(char **quote_ptr)
{
	static t_expantion		quote_expantions[] = {
		NULL, &single_quote_expantion, NULL, NULL,
	};

	(*quote_ptr)++;
	return (apply_expantion(quote_ptr,
		quote_expantions, double_quote_stop_condtion));
}
