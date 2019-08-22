/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 23:41:01 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 11:20:22 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		main(void)
{
	// init_termconfig();
	init_signal_handlers();
	while (1)
	{
		display_prompt();
		handle_input();
	}
}
