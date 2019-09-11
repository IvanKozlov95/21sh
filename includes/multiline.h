/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiline.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 07:31:26 by ikozlov           #+#    #+#             */
/*   Updated: 2019/09/10 22:01:28 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MULTILINE_H
# define MULTILINE_H

# include "dstring.h"

struct							s_multiline
{
	size_t			size;
	size_t			count;
	t_string		**lanes;
};

typedef struct s_multiline		t_multiline;

t_multiline						*multiline_init(size_t size);
t_multiline						*multiline_init_from_char_ptr(char *ptr);
void							multiline_destroy(t_multiline *m);
bool							multiline_apped_line(t_multiline *m);
bool							multiline_remove_line(t_multiline *m, int idx);
bool							multiline_instert_at(t_multiline *m, int line,
	int pos, char *add);
char							*multiline_to_char_ptr(t_multiline *m);
void							multiline_debug(t_multiline *m);


#endif
