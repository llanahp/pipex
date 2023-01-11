/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_upgrade_aux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:42:51 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/13 14:42:52 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cnt_wrds_upg2(char *s, char c, t_info *info, int aux)
{
	while (s[info->i] && ((s[info->i] != c && info->mark == 0)
			|| (s[info->i] != info->com && info->mark == 1)))
		info->i++;
	while (s[info->i] && ((s[info->i] == c && info->mark == 0)
			|| (s[info->i] == info->com && info->mark == 1)))
	{
		if (s[info->i] == info->com && info->mark == 1)
			info->mark = 0;
		info->i++;
	}
	if (((s[info->i] == '\'') | (s[info->i] == '"')) && info->mark == 0)
	{
		info->com = s[info->i];
		info->i++;
		info->words++;
		info->mark = 1;
	}
	else if ((char)s[info->i] == info->com && info->mark == 1 && aux == 0)
	{
		info->i++;
		info->mark = 0;
	}
}

void	updt_cntr_upg2(char const *s, char c, t_info *info, int aux)
{
	while (s[info->i] && ((s[info->i] != c && info->mark == 0)
			|| (s[info->i] != info->com && info->mark == 1)))
		info->i++;
	while (s[info->i] && ((s[info->i] == c && info->mark == 0)
			|| (s[info->i] == info->com && info->mark == 1)))
	{
		if (s[info->i] == info->com && info->mark == 1)
			info->mark = 0;
		info->i++;
	}
	if (((s[info->i] == '\'') | (s[info->i] == '"')) && info->mark == 0)
	{
		info->com = s[info->i];
		info->i++;
		info->mark = 1;
	}
	else if ((char)s[info->i] == info->com && info->mark == 1 && aux == 0)
	{
		info->i++;
		info->mark = 0;
	}
}
