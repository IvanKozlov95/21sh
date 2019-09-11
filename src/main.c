/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:41:01 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/11 15:14:30 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "21sh.h"
#include "command_line.h"

int		main(void)
{
	init_env();
	init_termconfig();
	init_command_line();
	init_signal_handlers();
	while (1)
	{
		g_command_line.cmds = multiline_init(10);
		g_command_line.current_line = 0;
		handle_input();
		multiline_destroy(g_command_line.cmds);
	}
}
