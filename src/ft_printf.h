/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/21 13:14:08 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_count_flags(const char *str);

int		ft_is_flag(char c);

char	*ft_get_flags(const char *str);

char	**ft_parse_flags(const char *flags, va_list args);

char	*ft_itoa_base(unsigned long n, char *base);

char	*ft_convert_to_string(char c);

char	*ft_strprefix(char *prefix, char *str);

char	*ft_ptoa(long n);
#endif