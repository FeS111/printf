/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:49:57 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/21 09:55:54 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_print(char *str, int *count, int is_flag)
{
	if (!str)
		return ;
	*count += ft_strlen(str);
	if (is_flag == 1 && str[0] == '\\' && str[1] == '\0')
		ft_putchar_fd('\0', 1);
	else
		ft_putstr_fd(str, 1);
	free(str);
}

int	ft_vprintf(const char *str, char **flags, int *count)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	j = 0;
	while (str[i + 1] != '\0')
	{
		if (str[i] == '%' && ft_is_flag(str[i + 1]))
		{
			ft_print(ft_substr(str, j, i - j), count, 0);
			j = i + 2;
			i++;
			ft_print(flags[k], count, 1);
			k++;
		}
		i++;
	}
	ft_print(ft_substr(str, j, ft_strlen(str) - j), count, 0);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	**flags;
	char	*unparsed_flags;
	int		res;

	res = 0;
	va_start (args, format);
	unparsed_flags = ft_get_flags(format);
	if (!unparsed_flags)
	{
		ft_putstr_fd((char *) format, 1);
		return (ft_strlen(format));
	}
	else
	{
		flags = ft_parse_flags(unparsed_flags, args);
		if (!flags)
			return (0);
		free(unparsed_flags);
		ft_vprintf(format, flags, &res);
		free(flags);
	}
	va_end (args);
	return (res);
}
