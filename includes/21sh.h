/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:31:47 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/09/06 05:05:58 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <term.h>
# include <termcap.h>
# include <errno.h>

# include "btree.h"
# include "dictionary.h"

# define SH_PREFIX "21sh: "
# define HOME "HOME"
# define OLDPWD "OLDPWD"
# define CDHOME "~"
# define CDHOME2 "--"
# define CDOLDPWD "-"
# define EXIT_SIGNAL 0

/*
**	General buffer size
*/
# define GNR_BUF_SIZE 100

extern t_dict					*g_env;

enum							e_21sh_errcodes
{
	error_default = -0x4200,
	error_unkn_atom = 0x4201,
	error_cur_pos,
};

typedef enum e_21sh_errcodes	t_21sh_errcodes;

/*
**	src/error.c
*/
void							fatal(const int exitcode, const char *fmt, ...);
void							set_error(int errcode, char *fmt, ...);

/*
**	src/termconfig/init.c
*/
void							reset_config(void);
void							init_termconfig(void);

/*
**	src/signal/init.c
*/

void							init_signal_handlers(void);

/*
**	src/signal/sigkill.c
*/

void							sigkill_handler(int signo);
void							sigquit_handler(int signo);

/*
**	src/execute.c
*/

void						execute_ast_tree(t_btree_node *ast);

/*
**	src/environ.c
*/

void						init_env(void);
bool						valid_env_name(char *name);

/*
**	src/builtins
*/
typedef int					(*t_builtin_func) (char *, char **);
t_builtin_func				get_builtin_func(char *name);
int							cd(char *name, char **args);
int							env(char *name, char **args);
int							echo(char *name, char **args);
int							exitt(char *name, char **args);
int							setenv_21sh(char *name, char **args);
int							unsetenv_21sh(char *name, char **args);

/*
**	src/keys
*/
bool						handle_special_keys(int key);
bool						handle_backspace_key(int key);
bool						handle_navigation_keys(int key);
bool						handle_ctrl_d(int key);
bool						handle_home_key(int key);
bool						handle_end_key(int key);

/*
**	debug
*/
# include "list.h"
void	debug(char *fmt, ...);
void	token_debug_info(t_list *elem);

#endif
