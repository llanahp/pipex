/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_upgrade.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:02:18 by ralopez-          #+#    #+#             */
/*   Updated: 2022/11/10 11:02:19 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cnt_wrds_upg(char *s, char c)
{
	t_info	info;
	int		aux;

	info.i = 0;
	info.mark = 0;
	info.words = 0;
	while (s[info.i])
	{
		aux = 0;
		if (s[info.i]
			&& ((s[info.i] == '\'') | (s[info.i] == '"')) && info.mark == 0)
		{
			info.com = s[info.i];
			info.words++;
			info.mark = 1;
			aux++;
		}
		else if (s[info.i] && s[info.i] == info.com && info.mark == 1)
			info.mark = 0;
		if (s[info.i] && s[info.i] != c && info.mark == 0)
			info.words++;
		cnt_wrds_upg2(s, c, &info, aux);
	}
	return (info.words);
}

int	str_wrd_upg(char *s, char c, char **spltr, t_info info)
{
	int		j;
	int		aux;

	j = info.i;
	while (s[j] && ((s[j] != c && info.mark == 0)
			|| (s[j] != info.com && info.mark == 1)))
		j++;
	(*spltr) = (char *)ft_calloc(((j - info.i) + 1), sizeof(char));
	if (!(*spltr))
		return (-1);
	j = info.i;
	aux = 0;
	while (s[j] && ((s[j] != c && info.mark == 0)
			|| (s[j] != info.com && info.mark == 1)))
	{
		(*spltr)[aux] = s[j];
		j++;
		aux++;
	}
	return (1);
}

int	clean_memory_upgrade(char ***splt, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free((*splt)[i]);
		i++;
	}
	free((*splt));
	return (0);
}

int	update_counter_upgrade(char const *s, char c, t_info *info)
{
	int	aux;

	aux = 0;
	info->words++;
	if (s[info->i]
		&& ((s[info->i] == '\'') | (s[info->i] == '"')) && info->mark == 0)
	{
		info->com = s[info->i];
		info->mark = 1;
		aux++;
	}
	else if (s[info->i] && s[info->i] == info->com && info->mark == 1)
		info->mark = 0;
	updt_cntr_upg2(s, c, info, aux);
	return (info->com);
}

char	**ft_split_upgrade(char const *s, char c)
{
	char	**splt;
	t_info	info;

	info.i = 0;
	info.words = 0;
	splt = NULL;
	info.mark = 0;
	if (s == NULL)
		return (NULL);
	splt = (char **)malloc(sizeof(char *) * (cnt_wrds_upg((char *)s, c) + 1));
	if (!splt)
		return (0);
	while (s[info.i])
	{
		if (s[info.i] && ((unsigned char *)s)[info.i] != (unsigned char)c
			&& (str_wrd_upg((char *)s, c, &(splt[info.words]), info) == -1))
		{
			clean_memory_upgrade(&splt, info.words);
			return (0);
		}
		info.com = update_counter_upgrade(s, c, &info);
	}
	splt[info.words] = NULL;
	return (splt);
}
