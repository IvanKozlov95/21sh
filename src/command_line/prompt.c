/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:35:12 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/01 18:30:16 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "colors.h"
#include "ftstring.h"
#include "ft_printf.h"

#include "21sh.h"
#include "command_line.h"

void	display_prompt(void)
{
	char		cwd[2048 + 1];

	getcwd(cwd, 2048);
	g_command_line.prompt_len =ft_printf("%s%s%s > ", BLU, cwd, RESET)
		- ft_strlen(BLU) - ft_strlen(RESET);
	debug("prompt len %d\n", g_command_line.prompt_len);
}
