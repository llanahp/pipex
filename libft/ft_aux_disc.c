/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_disc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:40:33 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/09 13:40:40 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	do_number(int n)
{
	char	*num;
	int		i;
	char	c;
	int		len;

	num = ft_itoa(n);
	i = 0;
	if (num == NULL)
		return (i);
	len = ft_strlen(num);
	while (len)
	{
		c = num[i];
		write(1, &c, 1);
		i++;
		len--;
	}
	free(num);
	return (i);
}

int	do_string(char *cad)
{
	int		i;
	char	c;

	if (cad == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (cad[i])
	{
		c = cad[i];
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	do_char(int cha)
{
	char	c;

	c = (int)cha;
	write(1, &c, 1);
	return (1);
}

int	do_percent(void)
{
	write(1, "%", 1);
	return (1);
}
