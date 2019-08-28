/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:29:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/27 02:42:25 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "21sh.h"
#include "ft_printf.h"

void		set_error(int errcode, char *fmt, ...)
{
	va_list		args;

	va_start(args, fmt);
	ft_dprintf(STDOUT_FILENO, SH_PREFIX);
	ft_vprintf(STDOUT_FILENO, &args, fmt);
	va_end(args);
	errno = errcode;
}

void		fatal(const int exitcode, const char *fmt, ...)
{
	va_list		args;

	va_start(args, fmt);
	ft_vprintf(STDOUT_FILENO, &args, fmt);
	va_end(args);
	exit(exitcode);
}
