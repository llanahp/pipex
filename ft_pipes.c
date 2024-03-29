/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:09:01 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/19 12:09:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** fds_pipes:
 * This function dups the input and output of two file descriptors.
 * 
 * If something went wrong, desalocate all memory and exit the program.
 */
void	fds_pipes(int in, int out, t_inf *info)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		free_memory(info);
		exit(EXIT_FAILURE);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		free_memory(info);
		exit(EXIT_FAILURE);
	}
}

/** close_pipes:
 * This function close the previous file descriptors to the actual command.
 */
void	close_pipes(t_inf *info)
{
	int	i;

	i = -1;
	while (++i < (2 * (info->n_cmd - 1)))
	{
		close(info->fds[i]);
	}
}

/** set_num_cmd:
 * This function malloc space to store the Files Descriptors (fd) of the pipes
 */
void	set_fds_pipes(t_inf *info)
{
	int	i;

	i = -1;
	info->fds = malloc(sizeof(info->fds) * 2 * (info->n_cmd - 1));
	if (info->fds == NULL)
		free_error("error malloc files descriptors pipes", "", "", info);
	while (++i < (info->n_cmd - 1))
	{
		if (pipe(info->fds + 2 * i) == -1)
			free_error("error create pipes", "", "", info);
	}
}
