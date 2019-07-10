/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:40:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/09 20:41:13 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "21sh.h"

void		init_signal_handlers(void)
{
	signal(SIGINT, sigkill_handler);
}
