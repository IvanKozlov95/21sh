/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:37:32 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/11 14:29:38 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "command_line.h"

/*
** Use the common idiom of 128 + signal number for signal exits.
** Alternative approach is to reset the signal to default handler,
** and immediately raise() it.
** Example:
** exit(128 + signo);
*/

void		sigkill_handler(int signo)
{
	(void)signo;
	ft_printf("\n");
}
