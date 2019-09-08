/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:56:11 by batman            #+#    #+#             */
/*   Updated: 2019/09/08 04:18:58 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "21sh.h"
#include "memory.h"
#include "ftstring.h"
#include "shell_command.h"

t_dict			*g_env;

static char		*find_cmd_path(char *cmd_name, struct stat *f)
{
	int				i;
	char			**paths;
	char			*tmp;
	char			*path_var;

	path_var = dict_find(g_env, "PATH", false);
	if (!path_var)
		return (NULL);
	paths = ft_strsplit(path_var, ':');
	i = -1;
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path_var = ft_strjoin(tmp, cmd_name);
		ft_free(1, tmp);
		if (lstat(path_var, f) != -1)
			break ;
		ft_strdel(&path_var);
	}
	darrfree((void **)paths);
	return (path_var);
}

static char			*get_path(char *cmd_name)
{
	struct stat		f;
	char			*path;
	bool			can_execute;

	can_execute = false;
	path = lstat(cmd_name, &f) == -1 ? find_cmd_path(cmd_name, &f) : ft_strdup(cmd_name);
	lstat(path, &f);
	can_execute = S_ISREG(f.st_mode) && (f.st_mode & S_IXUSR);
	if (S_ISDIR(f.st_mode) && !ft_strequ("", cmd_name))
		set_error(-1, "%s: is a directory\n", path);
	else if (S_ISREG(f.st_mode) && !(f.st_mode & S_IXUSR))
		set_error(-1, "Permission denied\n");
	else if (!S_ISREG(f.st_mode))
		set_error(-1, "command not found: %s\n", cmd_name);
	if (!can_execute)
		ft_free(1, path);
	return (can_execute ? path : NULL);
}

static void			duplicate_fd_if_present(int newfd, int oldfd)
{
	if (newfd)
		dup2(newfd, oldfd);
}

static void			prepare_redirect_out(t_shell_command *command)
{
	int		fd;

	if (command->redirect_out == NULL)
		return ;
	fd = open(command->redirect_out, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	debug("redirect out fd is %d\n", fd);
	if (fd < 0) {
		// perror(command->redirect_out);
		fatal(-1, "Remove fatal! Could not open file for redirect out\n");
	}
	command->redirect.out = fd;
	dup2(fd, STDOUT_FILENO);
}

void				execute_shell_command(t_shell_command *command)
{
	pid_t	pid;
	char	*path;
	int		status;

	if (ft_strlen(command->argv[0]) == 0)
		return ;
	path = get_path(command->argv[0]);
	pid = fork();
	if (pid < 0)
		fatal(-1, "fork failed\n");
	if (pid == 0)
	{
		duplicate_fd_if_present(command->pipe.in, STDIN_FILENO);
		duplicate_fd_if_present(command->pipe.out, STDOUT_FILENO);
		prepare_redirect_out(command);
		execve_wrapper(path, command);
		// show error message but restore a stdout first
	}
	else
		wait(&status);
}
