/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralopez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:27:42 by ralopez-          #+#    #+#             */
/*   Updated: 2022/10/11 10:27:43 by ralopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	do_pointer(unsigned long n, char *ER, int base)
{
	int	i;

	i = 0;
	if ((n / base) > 0)
		i = do_pointer((n / base), ER, base);
	write(1, &ER[n % base], 1);
	return (1 + i);
}

int	do_pointer_pre(unsigned long n, char *ER, int base)
{
	write(1, "0x", 2);
	return (2 + do_pointer(n, ER, base));
}
