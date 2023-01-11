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

/* pipes_child:
*	
*/
void	pipes_child(t_inf *info, int num)
{
	if (info->child == 0)
		fds_pipes(info->in_file, info->fds[1], info);
	else if ((info->child + 1) == info->n_cmd)
		fds_pipes(info->fds[2 * num - 2], info->out_file, info);
	else
		fds_pipes(info->fds[2 * num - 2], info->fds[2 * num + 1], info);

	if (info->in_file != -1)
		close(info->in_file);
	if (info->out_file != -1)
		close(info->out_file);
	close_pipes(info);
}

/** child:
 * 
 * 
*/
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
