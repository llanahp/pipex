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

void	fds_pipes(int in, int out, t_info *info)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		free_memory("Dup2",": ",strerror(errno), info);
	}
	if(dup2(out, STDOUT_FILENO) == -1)
	{
		free_memory("Dup2",": ",strerror(errno), info);
	}
	return (0);
}

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
		free_memory("error malloc files descriptors pipes","","", info);
	while (++i < (info->n_cmd - 1))
	{
		if (pipe(info->fds + 2 * i) == -1)
			free_memory("error create pipes","","", info);
	}
}
