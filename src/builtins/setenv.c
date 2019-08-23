/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:03 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/23 15:53:01 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "ftstring.h"
#include "ft_printf.h"

int		setenv_21sh(char *name, char **args)
{
	char	*env_name;
	char	*env_value;

	(void)name;
	env_name = *args;
	env_value = *(args + 1) ? *(args + 1) : "";
	if (!env_name)
		return (env(name, args));
	else if (valid_env_name(env_name))
		dict_insert(g_env, env_name, env_value);
	else
		set_error(-1, "setenv: Variable name must begin\
with a letter and contain only alphanumeric characters.\n");
	return (0);
}
