/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:37 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/23 15:46:32 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "21sh.h"
#include "ftstring.h"
#include "ft_printf.h"

int				echo(char *name, char **args)
{
	bool	printnl;

	(void)name;
	printnl = !ft_strequ(*args, "-n");
	args += !printnl;
	while (*args)
	{
		ft_printf("%s%s", *args, *(args + 1) ? " " : "");
		args++;
	}
	if (printnl)
		ft_printf("\n");
	return (0);
}
