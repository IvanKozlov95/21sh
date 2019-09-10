/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:35:12 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/08 16:30:55 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "colors.h"
#include "ftstring.h"
#include "ft_printf.h"

#include "21sh.h"
#include "command_line.h"

void	set_prompt(t_fsm_state state)
{
	if (state == state_quote)
		g_command_line.custom_prompt = "quote> ";
	else
		g_command_line.custom_prompt = NULL;
}

void	display_prompt(void)
{
	char		cwd[2048 + 1];

	getcwd(cwd, 2048);
	if (!g_command_line.custom_prompt)
		g_command_line.prompt_len =ft_printf("%s%s%s > ", BLU, cwd, RESET)
			- ft_strlen(BLU) - ft_strlen(RESET);
	else
		g_command_line.prompt_len =ft_printf("%s",
			g_command_line.custom_prompt);
	debug("prompt len %d\n", g_command_line.prompt_len);
}
