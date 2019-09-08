/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_wrapper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 20:04:34 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/07 21:35:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "dictionary.h"

#include "21sh.h"
#include "shell_command.h"

void		execve_wrapper(char *path, t_shell_command *cmd)
{
	char		**env;

	env = dict_to_darr2(g_env, "=", pair_to_str);
	execve(path, cmd->argv, env);
	darrfree((void **)env);
}
