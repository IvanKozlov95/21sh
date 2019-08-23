/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:16:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/28 18:42:14 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "ftstring.h"

t_dict	*g_env;

// todo: move to ternconfig

bool	valid_env_name(char *name)
{
	return (name && ft_isalpha(*name) && strisalnum(name));
}

void	init_env(void)
{
	size_t			i;
	extern char		**environ;
	char			*separator;

	i = -1;
	g_env = dict_init(0);
	while (environ[++i])
	{
		separator = ft_strchr((const char *)environ[i], '=');
		*separator = 0;
		dict_insert(g_env, environ[i], separator + 1);
	}
}
