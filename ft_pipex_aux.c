/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:09:01 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/19 12:09:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** set_num_cmd:
 * This function strore the number of commands need to be executed.
 */
void	set_num_cmd(t_inf	*info)
{
	if (ft_strcmp(info->argv[1], "here\\_doc") == 0)
		info->n_cmd = info->argc - 4;
	else
		info->n_cmd = info->argc - 3;
}

/** validate_arg:
 * This function verify all the pre-requisites to necesary to start executing 
 * the commands are correct.
 * Malloc space to store the numbers of the forks.
 * 
 * Returns 1 if all the validations are success
 * 
 * Returns -1 if any validation went wrong
 */
int	validate_arg(t_inf *info)
{
	if (info->argc < 5)
		return (msg("Number of arguments invalid", "", "", -1));
	if (info->argc < 6 && ft_strcmp(info->argv[1], "here\\_doc") == 0)
		return (msg("Number of arguments invalid", "", "", -1));
	if (validate_env(info) == -1)
		return (-1);
	open_input(info);
	open_output(info);
	set_num_cmd(info);
	set_fds_pipes(info);
	info->pid = malloc(sizeof(info->pid) * info->n_cmd);
	if (info->pid == NULL)
		free_error("Error malloc pids", "", "", info);
	return (1);
}

/** get_cmd:
 * This function returns, if exists and it can be access,
 *  the absolute path to the command.
 * First try whith the command because it can be the abslute path.
 * If they cant access, they try all the path from the enviroment.
 * 
 * Returns !(NULL) if all the validations are success
 * 
 * Returns NULL if any validation went wrong
 */
char	*get_cmd(t_inf *info, int numberChild)
{
	char	*cmd;
	char	*cmd2;
	int		i;
	int		len;

	i = -1;
	if (numberChild > info->n_cmd)
		return (NULL);
	cmd = info->argv[numberChild + 2];
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	info->args_cmd = ft_split_upgrade(cmd, ' ');
	while (info->paths[++i] != NULL)
	{
		cmd2 = ft_strjoin(info->paths[i], "/");
		len = ft_strlen(ft_strchr(cmd, ' '));
		cmd2 = ft_strjoin(cmd2, ft_substr(cmd, 0, ft_strlen(cmd) - len));
		if (access(cmd2, F_OK | X_OK) == 0)
			break ;
		free(cmd2);
		cmd2 = NULL;
	}
	return (cmd2);
}
