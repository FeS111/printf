/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:11:40 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/19 16:12:04 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_count_flags(const char *str)
{
	int	count;

	count = 0;
	while (*(str + 1) != '\0')
	{
		if (*str == '%' && ft_is_flag(*(str + 1)))
			count++;
		str++;
	}
	return (count);
}

char	*ft_get_flags(const char *str)
{
	char	*flags;
	int		i;
	int		k;

	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	flags = (char *) ft_calloc(ft_count_flags(str) + 1, sizeof(char));
	while (str[i +1] != '\0')
	{
		if (str[i] == '%' && ft_is_flag(str[i + 1]))
		{
			flags[k] = str[i + 1];
			k++;
		}
		i++;
	}
	return (flags);
}

char	**ft_parse_flags(const char *flags, va_list args)
{
	char	**res;
	int		i;
	char	c;
	char	*s;

	if (!flags)
		return (NULL);
	i = 0;
	res = ft_calloc(ft_strlen(flags) + 1, sizeof(char *));
	while (flags[i] != '\0')
	{
		if (flags[i] == 's')
			res[i] = va_arg(args, char *);
		if (flags[i] == 'd'|| flags[i] == 'i' || flags[i] == 'u')
			res[i] = ft_itoa(va_arg(args, int));
		if (flags[i] == 'c')
		{
			c = va_arg(args, int);
			res[i] = ft_strjoin(&c, "\0");
		}
		if (flags[i] == '%')
			res[i] = "%\0";
		if (flags[i] == 'x')
			res[i] = ft_itoa_base(va_arg(args, long), "0123456789abcdef");
		if (flags[i] == 'X')
			res[i] = ft_itoa_base(va_arg(args, long), "0123456789ABCDEF");
		if (flags[i] == 'p')
		{
			s = ft_itoa_base(va_arg(args, long), "0123456789abcdef");
			res[i] = ft_strjoin("0x", s);
		}
		i++;
	}
	return (res);
}
