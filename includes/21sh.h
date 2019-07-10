/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:31:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/28 18:41:07 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <term.h>
# include <termcap.h>

enum							e_21sh_errcodes
{
	error_default = -0x4200,
	error_unkn_atom = 0x4201,
	error_cur_pos,
};

typedef enum e_21sh_errcodes	t_21sh_errcodes;

/*
**	src/error.c
*/
void							fatal(const int exitcode, const char *fmt, ...);

/*
**	src/termconfig/init.c
*/
void							reset_config(void);
void							init_termconfig(void);

/*
**	src/command_line/prompt.c
*/
void							display_prompt(void);

/*
**	src/signal/init.c
*/

void							init_signal_handlers(void);

/*
**	src/signal/sigkill.c
*/

void							sigkill_handler(int signo);

#endif
