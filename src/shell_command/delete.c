/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:52:46 by batman            #+#    #+#             */
/*   Updated: 2019/08/22 17:55:38 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "ftstring.h"
#include "shell_command.h"

void				delete_shell_command(t_shell_command *command)
{
	int		i;

	i = -1;
	while (++i < command->argc)
		ft_free(1, command->argv[i]);
	ft_free(2, command->argv, command);
}
