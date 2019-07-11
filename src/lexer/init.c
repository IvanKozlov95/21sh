/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:42:13 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 13:52:52 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsm.h"
#include "lexer.h"

t_lexer			*init_lexer(char *input)
{
	static t_lexer		lexer;

	lexer.fsm = init_fsm();
	lexer.input = input;
	return (&lexer);
}
