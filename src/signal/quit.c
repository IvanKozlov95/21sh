/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 11:56:36 by ikozlov           #+#    #+#             */
/*   Updated: 2019/08/31 12:08:30 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "command_line.h"

/*
** Use the common idiom of 128 + signal number for signal exits.
** Alternative approach is to reset the signal to default handler,
** and immediately raise() it.
** Example:
** exit(128 + signo);
*/

void		sigquit_handler(int signo)
{
	destroy_command_line();
	exit(128 +signo);
}
