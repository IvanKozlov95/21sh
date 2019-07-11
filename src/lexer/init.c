/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:42:13 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/15 13:45:59 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer			*init_lexer(char *input)
{
	static t_lexer		lexer;

	lexer.current_state = fsm_start;
	lexer.input = input;
	return (&lexer);
}
