/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:11:40 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/20 14:20:17 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	if (k == 0)
	{
		free(flags);
		return (NULL);
	}
	return (flags);
}

char	*ft_parse_flag(char flag, va_list args)
{
	char	*s;

	if (flag == 's')
		return (va_arg(args, char *));
	if (flag == 'd' || flag == 'i' || flag == 'u')
		return (ft_itoa(va_arg(args, int)));
	if (flag == 'c')
		return (ft_convert_to_string(va_arg(args, int)));
	if (flag == '%')
		return (ft_convert_to_string('%'));
	if (flag == 'x')
		return (ft_itoa_base(va_arg(args, long), "0123456789abcdef"));
	if (flag == 'X')
		return (ft_itoa_base(va_arg(args, long), "0123456789ABCDEF"));
	if (flag == 'p')
	{
		s = ft_itoa_base(va_arg(args, long), "0123456789abcdef");
		return (ft_strjoin("0x", s));
	}
	return (NULL);
}

char	**ft_parse_flags(const char *flags, va_list args)
{
	char	**res;
	int		i;
	int		k;

	if (!flags)
		return (NULL);
	i = 0;
	k = -1;
	res = ft_calloc(ft_strlen(flags) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (flags[i] != '\0')
	{
		res[i] = ft_parse_flag(flags[i], args);
		if (!res[i])
		{
			while (k++ < i)
				free(res[k]);
			free(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}
