/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termconf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:40:24 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/27 01:54:26 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCONF_H
# define TERMCONF_H

# include <term.h>
# include <termcap.h>
# include <termios.h>

# include "output.h"

struct							s_descriptions
{
	char				*cm;
};

typedef struct s_descriptions	t_descriptions;

struct							s_termconf
{
	int					descriptor;
	struct termios		attr;
	struct termios		default_attr;
	/*
	**	capabilities
	*/
	char				*cm;
};
typedef struct s_termconf		t_termconf;

extern t_termconf				g_termconf;

# define SETTERMCMD(id) ({char *v = tgetstr(id, 0); tputs(v, 1, ft_putc_err);})

#endif
