/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 15:59:09 by batman            #+#    #+#             */
/*   Updated: 2019/09/04 13:45:22 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

t_builtin_func	get_builtin_func(char *name)
{
	static t_dict_pair	funcs[] = {
		(t_dict_pair){ .key = "cd", .val = cd },
		(t_dict_pair){ .key = "env", .val = env },
		(t_dict_pair){ .key = "echo", .val = echo },
		(t_dict_pair){ .key = "exit", .val = exitt },
		(t_dict_pair){ .key = "setenv", .val = setenv_21sh },
		(t_dict_pair){ .key = "unsetenv", .val = unsetenv_21sh } };
	static t_dict		disp = { .count = 6, .capacity = 6, .values = funcs };

	return (dict_find(&disp, name, false));
}
