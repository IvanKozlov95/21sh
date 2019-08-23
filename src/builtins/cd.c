/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 02:41:02 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/23 15:44:17 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/param.h>

#include "21sh.h"
#include "ftstring.h"

static void		cd_error(char *path)
{
	char	*msg;

	if (access(path, F_OK) == -1)
		msg = "No such file or directory";
	else if (access(path, R_OK) == -1)
		msg = "Permission denied";
	else
		msg = "Not a directory";
	set_error(-1, "cd: %s: %s", msg, path);
}

static char		*get_path(char **args)
{
	char	*ret;
	char	*home;
	char	*oldpwd;

	ret = *args;
	home = dict_find(g_env, HOME);
	oldpwd = dict_find(g_env, OLDPWD);
	if (!ret || ft_strequ(ret, CDHOME) || ft_strequ(ret, CDHOME2))
		ret = home;
	else if (ft_strequ(ret, CDOLDPWD))
		ret = oldpwd;
	return (ret);
}

int				cd(char *name, char **args)
{
	int		ret;
	char	*path;
	char	cwd[MAXPATHLEN];

	(void)name;
	ft_bzero(cwd, MAXPATHLEN);
	path = get_path(args);
	getcwd(cwd, MAXPATHLEN);
	ret = chdir(path);
	if (ret == 0)
		dict_insert(g_env, OLDPWD, cwd);
	else
		cd_error(path);
	return (0);
}
