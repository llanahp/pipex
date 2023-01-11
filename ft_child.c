/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:36 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/07 16:48:37 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipes_child(t_inf *info, int num)
{
	if (info->child == 0)
	{
		if (fds_pipes(info->in_file, info->fds[1]) == -1)
		{
			//TODO free memoria
			exit(1);
		}
	}
	//else if ((num + 1) == info->n_cmd)
	else if (info->child == info->n_cmd -1)
	{
		if (fds_pipes(info->fds[2 * num - 2], info->out_file) == -1)
		{
			//TODO free memoria
			exit(1);
		}
	}else
	{
		if (fds_pipes(info->fds[2 * num - 2], info->fds[2 * num + 1]) == -1 )
		{
			//TODO free memoria
			exit(1);
		}
	}

	if (info->in_file != -1)
		close(info->in_file);
	if (info->out_file != -1)
		close(info->out_file);
	close_pipes(info);
}

int	child(t_inf *info, char *cmd)
{
	pipes_child(info, (*info).child);
	if (info->args_cmd == NULL || cmd == NULL)
		exit(1);
	if (execve(cmd, info->args_cmd, info->env) == -1)
		return (msg("Execve", ": ", strerror(errno), -1));
	if (cmd != NULL)
		free(cmd);
	return (0);
}
