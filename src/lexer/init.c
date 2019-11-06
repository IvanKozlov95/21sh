/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:42:13 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/11/05 21:21:18 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

#include "lexer.h"

void			lexer_default_state(t_lexer *lexer)
{
	if (lexer->current_state != state_op)
		lexer->op_type = unkn;
	if (lexer->current_state != state_quote)
		lexer->quote_type = unkn;
}

void			lexer_default_state_step(t_lexer *lexer)
{
	if (lexer->current_state == state_delim_token)
		lexer->current_state = state_start;
	lexer->op_type = unkn;
}

t_lexer			*init_lexer(void)
{
	static t_lexer		lexer;

	lexer_default_state(&lexer);
	lexer.current_state = state_start;
	lexer.lexeme = string_init(0);
	return (&lexer);
}
