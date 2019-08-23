/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:21:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/23 15:53:11 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		unsetenv_21sh(char *name, char **args)
{
	(void)name;
	if (!*args)
		set_error(-1, "unsetenv: Too few arguments.\n");
	else
		while (*args)
		{
			dict_remove(g_env, *args);
			args++;
		}
	return (0);
}
