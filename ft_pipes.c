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

int	fds_pipes(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		return (msg("Dup2",": ",strerror(errno), -1));
	}
	if(dup2(out, STDOUT_FILENO) == -1)
	{
		return (msg("Dup2",": ",strerror(errno), -1));
	}
	return (0);
}

void	close_pipes(t_inf *info)
{
	int	i;

	i = 0;
	while (i < (2 * (info->n_cmd - 1)))
	{
		close(info->fds[i]);
		i++;
	}
}

int	set_fds_pipes(t_inf *info)
{
	int	i;

	i = -1;
	//info->fds = malloc(sizeof(int *) * 2 * info->n_cmd);
	info->fds = malloc(sizeof * info->fds * 2 * (info->n_cmd - 1));
	if (info->fds == NULL)
		return (msg("error malloc files descriptors pipes","","", -1));
	while (++i < (info->n_cmd - 1))
	{
		if (pipe(info->fds + 2 * i) == -1)
		{
			free(info->fds);
				return (msg("error create pipes","","", -1));
		}
	}
	return (0);
}
