/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batman <ikozlov@student.42.us.org>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:41:01 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/08/28 14:03:29 by batman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
#include "command_line.h"

int		main(void)
{
	init_env();
	init_termconfig();
	init_signal_handlers();
	while (1)
	{
		display_prompt();
		init_command_line();
		handle_input();
	}
}
