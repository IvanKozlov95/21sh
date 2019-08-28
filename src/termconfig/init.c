/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:27:50 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/28 00:14:15 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "21sh.h"
#include "memory.h"
#include "termconf.h"

t_termconf		g_termconf;

static void		init_terminal_data(void)
{
	int		success;
	char	*termtype;
	char	buf[1024];

	termtype = getenv("TERM");
	if (termtype == NULL)
		fatal(error_default, "Specify a terminal type with\
`setenv TERM <yourtype>'.\n");
	success = tgetent(buf, termtype);
	if (success < 0)
		fatal(error_default, "Could not access the termcap data base.\n");
	if (success == 0)
		fatal(error_default, "Terminal type `%s' is not defined.\n", termtype);
}

static int		set_terminal_descriptor(void)
{
	if (isatty(STDOUT_FILENO))
		g_termconf.descriptor = STDOUT_FILENO;
	else if (isatty(STDIN_FILENO))
		g_termconf.descriptor = STDIN_FILENO;
	else if (isatty(STDERR_FILENO))
		g_termconf.descriptor = STDERR_FILENO;
	else
		return (errno = ENOTTY);
	return (0);
}

static	int		set_terminal_capabilities(void)
{
	g_termconf.cm = tgetstr("cm", NULL);
	if (!g_termconf.cm)
		return (errno = ENOTTY);
	return (0);
}

void			reset_config(void)
{
	tcsetattr(g_termconf.descriptor, TCSANOW, &(g_termconf.default_attr));
}

void			init_termconfig(void)
{
	init_terminal_data();
	if (set_terminal_descriptor())
		fatal(errno, "No terminal desctriptor availiable\n");
	if (set_terminal_capabilities())
		fatal(errno, "Couldn't find capability needed\n");
	atexit(reset_config);
	tcgetattr(g_termconf.descriptor, &(g_termconf.attr));
	tcgetattr(g_termconf.descriptor, &(g_termconf.default_attr));
	g_termconf.attr.c_lflag &= ~(ICANON | ECHO | ECHOE);
	g_termconf.attr.c_cc[VMIN] = 1;
	g_termconf.attr.c_cc[VTIME] = 1;
	tcsetattr(g_termconf.descriptor, TCSANOW, &(g_termconf.attr));
}
