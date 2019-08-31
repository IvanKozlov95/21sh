/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:41:32 by ikozlov           #+#    #+#             */
/*   Updated: 2019/08/31 06:57:31 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keys.h>

#include "command_line.h"

bool		handle_home_key(int key)
{
	if (key == KHOME)
	{
		move_cursor_home();
		debug("home button pressed\n");
		return (true);
	}
	return (false);
}
