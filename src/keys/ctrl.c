/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:04:39 by ikozlov           #+#    #+#             */
/*   Updated: 2019/08/31 07:14:33 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"

#include "21sh.h"

bool		handle_ctrl_d(int key)
{
	if (key == KCTRL_D)
	{
		// todo: quit running job if any
		debug("ctrl + d is pressed\n");
		return (true);
	}
	return (false);
}
