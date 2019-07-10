/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:37:32 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/28 14:14:38 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		sigkill_handler(int signo)
{
	/*
	** Use the common idiom of 128 + signal number for signal exits.
	** Alternative approach is to reset the signal to default handler,
	** and immediately raise() it.
	*/
	exit(128 + signo);
}
