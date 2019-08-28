/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 19:00:57 by batman            #+#    #+#             */
/*   Updated: 2019/08/27 18:20:10 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "keys.h"
#include "libft.h"
#include "command_line.h"

static bool			handle_arrow_up_down(int key)
{
	if (key == KUP || key == KDOWN)
	{
		move_cursor(0, key == KUP ? -1 : 1);
		return (true);
	}
	return (false);
}

static bool			handle_arrow_left_right(int key)
{
	if (key == KLEFT || key == KRIGHT)
	{
		move_cursor(key == KLEFT ? -1 : 1, 0);
		return (true);
	}
	return (false);
}

bool				handle_navigation_keys(int key)
{
	return (handle_arrow_left_right(key) || handle_arrow_up_down(key));
}
