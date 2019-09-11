/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 05:17:26 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 05:19:06 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "keys.h"

bool			handle_enter_key(int key)
{
	if (key == KENTER)
	{
		debug("enter was pressed\n");
		return (true);
	}
	return (false);
}