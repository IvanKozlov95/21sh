/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 06:06:50 by ikozlov           #+#    #+#             */
/*   Updated: 2019/11/05 20:57:02 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "ftstring.h"

#include "21sh.h"

char	*debug_str_rule_result(int result)
{
	int			idx;
	static char	string_rule[100];
	static char	*results[] = {
		"RULE_NO_APPLY ", "RULE_ADD_ATOM ", "RULE_MOVE_ATOM ",
		"RULE_END_INPUT ", "RULE_NO_ACTION ", NULL,
	};

	if (result == 0)
		return ("RULE_NO_APPLY");
	ft_bzero(string_rule, 100);
	idx = 1;
	while (result > 0)
	{
		if (result & 1)
			ft_strcat(string_rule, results[idx]);
		result >>= 1;
		idx++;
	}
	return (string_rule);
}

char	*debug_str_rule(int rule_file_idx)
{
	static char	*rules[] = {
		"1", "2_3", "4", "5", "6", "7_8", "9", "10", "11",
	};

	return (rules[rule_file_idx]);
}

void	debug(char *fmt, ...)
{
	FILE		*f;
	va_list		va;

	f = fopen("/tmp/21.txt", "a");
	if (!f)
		fatal(-1, "Can't open log file.\n");
	va_start(va, fmt);
	vfprintf(f, fmt, va);
	va_end(va);
	fclose(f);
}
