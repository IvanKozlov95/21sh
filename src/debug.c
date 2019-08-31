/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:06:50 by ikozlov           #+#    #+#             */
/*   Updated: 2019/08/31 06:13:12 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "21sh.h"

void	debug(char *fmt, ...)
{
	FILE		*f;
	va_list		va;

	f = fopen("/tmp/21.txt", "a");
	if (!f)
		fatal(-1, "Can't open log file.\n");
	va_start(va, fmt);
	vfprintf(f, fmt, va);
	va_end(va);
	fclose(f);
}
