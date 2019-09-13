/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:40:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/31 12:08:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "21sh.h"

void		init_signal_handlers(void)
{
	signal(SIGINT, sigkill_handler);
	signal(SIGINT, sigquit_handler);
	signal(SIGABRT, sigquit_handler);
	signal(SIGSTOP, sigquit_handler);
	signal(SIGKILL, sigquit_handler);
	signal(SIGQUIT, sigquit_handler);
	signal(SIGWINCH, sigwinch_handler);
}
