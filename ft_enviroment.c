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

/** get_enviroment:
 * This function is called after verify that enviroment exist
 * Iterates all enviroment string to since find the string "PATH=" 
 * or reach the end
 * 
 * Returns 1 if string "PATH=" is find and store the rest of the string 
 * in info.paths splited by character ':'.
 * 
 * Returns -1 enviroment dosen´t containst "PATH=".
 */
int	get_enviroment(char **env, t_inf *info)
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

/** get_enviroment:
 * This function is called after verify that enviroment exist
 * Iterates all enviroment string to since find the string "PATH=" 
 * or reach the end
 * 
 * Returns 1 if string "PATH=" is find and store the rest of the string 
 * in info.paths splited by character ':'
 * 
 * Returns -1 enviroment dosen´t containst "PATH="
 */
void	clean_paths(t_inf *info)
{
	int	i;

	i = -1;
	while (info->paths[++i] != NULL)
		free(info->paths[i]);
	free(info->paths);
}

/** validate_env:
 * This function verify if the enviroment of the program is null
 * 
 * Returns, if enviroment exist, the value of function get_env
 * 
 * Returns -1 if something goes wrong
 */
int	validate_env(t_inf *info)
{
	if (!info->env || info->env[0][0] == '\0')
		return (msg("Enviroment is null", "", "", -1));
	return (get_enviroment(info->env, info));
}
