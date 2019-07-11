/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 09:06:14 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/07/10 16:13:43 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSM_H
# define FSM_H

# include <stdbool.h>

enum						e_atom_type
{
	unkn = -1,
	term = 0,
	whitespc,
	nonterm,
	double_nonterm,
	eos,
	atom_type_count
};
typedef enum e_atom_type	t_atom_type;

struct						s_fsm_state
{
	bool					final;
	int						out[atom_type_count];
};
typedef struct s_fsm_state	t_fsm_state;

/*
**	FSM(finite state machine)
*/
struct						s_fsm
{
	t_fsm_state				start;
	t_fsm_state				current;
	t_fsm_state				*states;
};
typedef struct s_fsm			t_fsm;

t_fsm						*init_fsm(void);

#endif
