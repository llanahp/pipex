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

int free_memory(t_inf *info){
    if (ft_strcmp(info->argv[1], ".here\\_doc") == 0)
        unlink(info->argv[1]);
   return (999999999);
}

/** msg:
 * This function display an error message.
 * 
 * Returns ther code that recive as argument
 */
int msg(char *str1,char *str2, char *str3, int code){
    ft_putstr_fd("pipex: ", 2);
    ft_putstr_fd(str1, 2);
    ft_putstr_fd(str2, 2);
    ft_putendl_fd(str3, 2);
    return (code);
}