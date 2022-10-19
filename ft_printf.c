/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:49:57 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/19 16:35:28 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	ft_vprintf(const char *str, va_list args, char **flags)
{
	int		i;
	int		k;
	int		j;

	if (!str)
		return (1);
	i = 0;
	k = 0;
	j = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == '%' && ft_is_flag(str[i + 1]))
		{
			ft_putstr_fd(ft_substr(str, j, i - j), 1);
			j = i + 2;
			i++;
			ft_putstr_fd(flags[k], 1);
			k++;
		}
		i++;
	}
	ft_putstr_fd(ft_substr(str, j, ft_strlen(str) - j), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	**flags;
	char	*unparsed_flags;

	va_start (args, format);
	unparsed_flags = ft_get_flags(format);
	flags = ft_parse_flags(unparsed_flags, args);
	ft_vprintf(format, args, flags);
	va_end (args);
	return (0);
}
