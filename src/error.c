/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:29:06 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 16:02:17 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "ft_printf.h"

void		set_error(int errcode, char *fmt, ...)
{
	errno = errcode;
		va_list		args;

	va_start(args, fmt);
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
