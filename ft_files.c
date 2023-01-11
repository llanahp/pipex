/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:36 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/07 16:48:37 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	read_temp(t_inf *info)
{
	char	*buf;

	info->in_file = open(".here\\_doc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (info->in_file < 0)
		return (msg("here\\doc:","",strerror(errno), 1));
	while (1 == 1)
	{
		buf = NULL;
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (buf == NULL)
			exit(1);
		if (ft_strcmp(buf, info->argv[2]) == 0)
			break ;
		write(info->in_file, &buf, ft_strlen(buf));
		write(info->in_file, "\n", 1);
		free(buf);
	}
	close (info->in_file);
	info->argv[1] = ".here\\_doc";
	return (0);
}

int	open_input(t_inf *info)
{
	if (ft_strcmp((*info).argv[1], "here\\_doc") == 0)
		read_temp(info);
	info->in_file = open (info->argv[1], O_RDONLY, 644);
	if (info->in_file < 0)
	{
		if (ft_strcmp(info->argv[1], ".here\\_doc") == 0){
			unlink(".here\\_doc");
			msg("here\\doc:", "", strerror(errno), 1);
			exit(1);
		}
		return (msg(strerror(errno), ": ", info->argv[1],1));
	}
	return (0);
}

int	open_output(t_inf *info)
{
	char	*fd;

	fd = info->argv[info->argc - 1];
	if (ft_strcmp((*info).argv[1], "here\\_doc") == 0)
		info->out_file = open(fd, O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		info->out_file = open(fd, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->out_file < 0)
		return (msg(strerror(errno), ": ", info->argv[info->argc - 1], -1));
	return (0);
}
