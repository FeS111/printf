/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:11:40 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/30 14:25:09 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_is_flag(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%' || c == 'i')
		return (1);
	return (0);
}

int	ft_p(char *str, int is_s_flag)
{
	int	res;

	if (is_s_flag == 1 && str)
		str = ft_strdup(str);
	if (!str)
		str = ft_strdup("(null)");
	ft_putstr_fd(str, 1);
	res = ft_strlen(str);
	free(str);
	return ((int) res);
}

int	ft_print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
