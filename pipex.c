/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:48:36 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/07 16:48:37 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	see_leaks()
{
	system("leaks pipex");
}

/** wait_childs:
 * This function is called after execute all commands.
 * Close the input and output file. Also the file descriptors of the pipes.
 * 
 * Waits for all the childs and return the last exit code status.
 * 
 * If it´s the last child, they store her exit status.
 * WIFEXITED(status) returns != 0 if the child ends correctly.
 * WEXITSTATUS(status) returns the output status of last child.
 */
int	wait_childs(t_inf *info)
{
	int	id;
	int	status;
	int	exit_cod;

	status = 1;
	info->child--;
	if (info->in_file != -1)
		close(info->in_file);
	if (info->out_file != -1)
		close(info->out_file);
	close_pipes(info);
	while (info->child >= 0)
	{
		id = waitpid(info->pid[info->child], &status, 0);
		if (id == info->pid[info->n_cmd - 1])
		{
			if ((info->child == (info->n_cmd - 1)) && WIFEXITED(status))
				exit_cod = WEXITSTATUS(status);
		}
		info->child--;
	}
	free_memory(info);
	return (exit_cod);
}

/* main:
*	Creates the principal structure tu store info, t_info.
*	Returns the last child's exit code.
*/
int	main(int argc, char **argv, char **env)
{
	t_inf	info;
	char	*temp;

	info.env = env;
	info.argc = argc;
	info.argv = argv;
	info.child = -1;
	if (validate_arg(&info) == -1)
		exit (EXIT_FAILURE);
	while (++info.child < info.n_cmd)
	{
		info.pid[info.child] = fork();
		if (info.pid[info.child] == -1)
			free_error("fork", ": ", strerror(errno), &info);
		else if (info.pid[info.child] == 0)
		{
			temp = get_cmd(&info, info.child);
			child(&info, temp);
			free_arguments_cmd(&info);
		}
	}
	return (wait_childs(&info));
}
