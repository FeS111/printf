/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/19 16:39:29 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_count_flags(const char *str);

int		ft_is_flag(char c);

char	*ft_get_flags(const char *str);

char	**ft_parse_flags(const char *str, va_list args);

char	*ft_itoa_base(long long n, char *base);
#endif