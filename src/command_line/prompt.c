/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:35:12 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/09 20:35:56 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "colors.h"
#include "ft_printf.h"

void	display_prompt(void)
{
	char	cwd[2048 + 1];

	getcwd(cwd, 2048);
	ft_printf("%s%s%s > ", BLU, cwd, RESET);
}
