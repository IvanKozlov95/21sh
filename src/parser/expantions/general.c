/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 04:01:02 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/06 05:58:15 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "dstring.h"
#include "ftstring.h"

#include "parser.h"

static void		default_action(char **token_ptr, t_string *expanded_token)
{
	string_appendn(expanded_token, *token_ptr, 1);
	(*token_ptr)++;
}

static void		apply_expantion_wrapper(char **token_ptr,
	t_string *expanded_token, t_expantion expantion)
{
	char	*expantion_result;

	expantion_result = expantion(token_ptr);
	if (!expantion_result)
		return ;
	string_append(expanded_token, expantion_result);
	ft_free(1, expantion_result);
}

static bool		default_stop_condition(char current)
{
	return (current == '\0');
}

char			*apply_expantion(char **token_ptr, t_expantion expantions[],
	bool (*stop_condition)(char c))
{
	char			*token;
	t_expantion		expantion;
	t_string		*expanded_token;

	token = *token_ptr;
	expanded_token = string_init(ft_strlen(token));
	while (*token)
	{
		expantion = expantions[get_atom_type(*token)];
		if (expantion)
			apply_expantion_wrapper(&token, expanded_token, expantion);
		else if (stop_condition && stop_condition(*token))
		{
			token++;
			break ;
		}
		else
			default_action(&token, expanded_token);
	}
	*token_ptr = token;
	return (string_destroy(expanded_token, true));
}

char		*expand_token(char *token)
{
	static t_expantion		general_expantions[] = {
		NULL, &single_quote_expantion, &double_quote_expantion, NULL,
		&argument_expantion,
	};

	return (apply_expantion(&token, general_expantions, default_stop_condition));
}
