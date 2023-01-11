/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enviroment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:09:01 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/19 12:09:03 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_env(char **env, t_inf *info)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[i] != NULL && env[i][0] != '\0'
		&& ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (ft_strncmp(env[i], "PATH=", 5) != 0)
		return (-1);
	else
	{
		temp = ft_substr(env[i], 5, ft_strlen(env[i]));
		info->paths = ft_split(temp, ':');
		free(temp);
		return (1);
	}
}

void	clean_paths(t_inf *info)
{
	int	i;

	i = -1;
	while (info->paths[++i] != NULL)
		free(info->paths[i]);
	free(info->paths);
}

int	validate_env(t_inf *info)
{
	if (!info->env || info->env[0][0] == '\0')
		return (msg("Unexpected error.","","", -1));
	return (get_env(info->env, info));
}
