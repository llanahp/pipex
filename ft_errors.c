/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:09:01 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/19 12:09:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/** free_arguments_cmd:
 * This function desalocate the arguments of the command.
 */
void	free_arguments_cmd(t_inf *info)
{
	int	i;

	i = -1;
	while(info->args_cmd[++i] !=  NULL)
		free(info->args_cmd[i]);
	free(info->args_cmd);
}

/** free_memory:
 * This function is called when something went wrong.
 * Release all information and exit the program whith Failure code(1).
 */
void	free_memory(char *str1,char *str2, char *str3, t_inf *info)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);

	if (info != NULL){
		if (ft_strcmp(info->argv[1], ".here\\_doc") == 0)
			unlink(info->argv[1]);
		if (info->pid != NULL)
			free(info->pid);
		if (info->fds != NULL)
			free(info->fds);
		if (info->args_cmd != NULL)
			free_arguments_cmd(info);
	}
	exit(EXIT_FAILURE);
}

/** msg:
 * This function display an error message.
 * 
 * Returns ther code that recive as argument
 */
int	msg(char *str1,char *str2, char *str3, int code){
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putendl_fd(str3, 2);
	return (code);
}