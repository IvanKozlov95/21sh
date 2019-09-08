/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_innout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:21:53 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/07 23:23:12 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_command.h"

t_innout		empty_innout(void)
{
	t_innout		innout;

	innout.in = 0;
	innout.out = 0;
	return (innout);
}
