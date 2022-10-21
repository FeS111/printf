/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:05:12 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/21 10:50:23 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_count_digit(unsigned long n, int base)
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

char	*ft_strprefix(char *prefix, char *str)
{
	char	*res;

	res = ft_strjoin(prefix, str);
	free(str);
	return (res);
}

char	*ft_ptoa(long n)
{
	char	*res;

	res = ft_itoa_base(n, "0123456789abcdef");
	return (ft_strprefix("0x", res));
}

char	*ft_convert_to_string(char c)
{
	char	*s;

	s = ft_calloc(3, sizeof(char));
	if (c == '\0')
	{
		s[0] = '\\';
		s[1] = c;
	}
	else
		s[0] = c;
	return (s);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	size_t		len;
	char		*itoa;

	len = ft_count_digit(n, 16);
	itoa = ft_calloc(len + 1, sizeof(char));
	if (!itoa)
		return (NULL);
	if (n == 0)
		itoa[0] = '0';
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
