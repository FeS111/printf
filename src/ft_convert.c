/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:05:12 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/19 15:36:43 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_count_digit(long long n, int base)
{
	size_t	ans;

	if (n < 0)
		ans = 1;
	else
		ans = 0;
	while (n)
	{
		ans++;
		n /= base;
	}
	return (ans);
}

char	*ft_itoa_base(long long n, char *base)
{
	size_t		len;
	char		*itoa;

	len = ft_count_digit(n, 16);
	itoa = ft_calloc(len + 1, sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[len] = 0;
	if (n < 0)
	{
		itoa[0] = '-';
		n = -n;
	}
	while (len-- && n)
	{
		itoa[len] = base[n % 16];
		n /= 16;
	}
	return (itoa);
}
