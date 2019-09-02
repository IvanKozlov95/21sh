/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:41:32 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/01 18:20:48 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keys.h>

#include "command_line.h"

bool		handle_home_key(int key)
{
	if (key == KHOME)
	{
		move_cursor_home();
		return (true);
	}
	return (false);
}
