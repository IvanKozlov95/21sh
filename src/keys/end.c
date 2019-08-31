/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:54:00 by ikozlov           #+#    #+#             */
/*   Updated: 2019/08/31 06:56:37 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keys.h>

#include "command_line.h"

bool		handle_end_key(int key)
{
	if (key == KEND)
	{
		move_cursor_end();
		return (true);
	}
	return (false);
}
