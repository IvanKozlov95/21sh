/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 08:42:57 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 13:56:15 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "fsm.h"

enum						e_token_type
{
	command = 0
};
typedef enum e_token_type	t_token_type;

struct						s_token
{
	t_token_type			type;
	char					*value;
};
typedef struct s_token		t_token;

struct						s_lexer
{
	t_fsm					*fsm;
	char					*input;
};
typedef struct s_lexer		t_lexer;

/*
**	src/lexer/init.c
*/
t_lexer						*init_lexer(char *input);

/*
**	src/lexer/next.c
*/
t_token						*next_token(t_lexer *lexer);

#endif
