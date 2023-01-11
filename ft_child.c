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
* Depend of the number of child, dups input and output to the corresponded ones
* and close the Files Descriptors (FD)
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
 * This function is called by the child of the fork
 * Dup and close the pipes and execute the command
*/
void	child(t_inf *info, char *cmd)
{
	int	argu;

	argu = info->child + 2;
	pipes_child(info, info->child);
	//TODO revisar este aparatado
	if (info->args_cmd == NULL || cmd == NULL)
	{
		if (cmd == NULL)
			free_error("command not found", ": ", info->argv[argu], info);
		if (cmd != NULL)
			free(cmd);
		free_error("", "", "", info);
	}
	if (execve(cmd, info->args_cmd, info->env) == -1)
	{
		if (cmd != NULL)
			free(cmd);
		free_error("Execve", ": ", strerror(errno), info);
	}
	if (cmd != NULL)
		free(cmd);
}
