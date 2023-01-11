/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:49:15 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/07 16:49:16 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <unistd.h>
# include <aio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_inf
{
	char	**argv;
	char	**args_cmd;
	int		argc;
	int		*fds;
	char	**env;
	char	**paths;
	int		*pid;
	int		in_file;
	int		out_file;
	int		n_cmd;
	int		child;

}	t_inf;

int		main(int argc, char **argv, char **env);
char	**ft_split_upgrade(char const *s, char c);
int		get_enviroment(char **env, t_inf *info);
void	set_num_cmd(t_inf	*info);
int		validate_arg(t_inf *info);
char	*get_cmd(t_inf *info, int n);
int		validate_env(t_inf *info);
void	open_input(t_inf *info);
void	open_output(t_inf *info);
void	child(t_inf *info, char *cmd);
void	close_pipes(t_inf *info);
void	fds_pipes(int in, int out,t_inf *info);
void	set_fds_pipes(t_inf *info);
char	*get_next_line(int fd);
void	clean_paths(t_inf *info);
int		msg(char *str1, char *str2, char *str3, int code);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	free_error(char *str1,char *str2, char *str3, t_inf *info);
void	free_memory(t_inf *info);
#endif
