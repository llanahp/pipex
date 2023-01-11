/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:36 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/07 16:48:37 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	see_leaks()
{
	system("leaks pipex");
}

int	main(int argc, char **argv, char **env)
{
	t_inf	info;
	char	*temp;
	int		exit_cod;

	info.env = env;
	info.argc = argc;
	info.argv = argv;
	exit_cod = 0;
	if (validate_arg(&info) == -1)
		exit (EXIT_FAILURE);
	info.child = 0;
	info.pid = malloc(sizeof * info.pid * info.n_cmd);
	if (info.pid == NULL)
		return (msg("Malloc", ": ", strerror(errno), -1));
	while (info.child < info.n_cmd)
	{
		info.pid[info.child] = fork();
		if (info.pid[info.child] == -1)
			return (msg("Pipe", ": ", strerror(errno), -1));
		else if (info.pid[info.child] == 0)
		{
			
			temp = get_cmd(&info, info.child);
			if (child(&info, temp) == -1)
				exit (EXIT_FAILURE);
		}
		info.child++;
	}
	info.child--;
	int espera;
	int status;

	if (info.in_file != -1)
		close(info.in_file);
	if (info.out_file != -1)
		close(info.out_file);
	close_pipes(&info);
	while (info.child >= 0)
	{
		//TODO Analiar el siguiente codigo
		espera = waitpid(info.pid[info.child], &status, 0);
		
		if (espera == info.pid[info.n_cmd - 1])
		{
			if ((info.child == (info.n_cmd - 1)) && WIFEXITED(status))
				exit_cod = WEXITSTATUS(status);
		}
		info.child--;
	}
	if (info.paths != NULL)
		clean_paths(&info);
	if (!info.pid)
		free(info.pid);
	if (!info.fds)
		free(info.fds);
	close(info.in_file);
	close(info.out_file);
	return (exit_cod);
}
