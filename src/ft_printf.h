/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/31 23:46:30 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);

int		ft_pstr(char *str, int is_s_flag);

int		ft_print_char(char c);

int		ft_is_flag(char c);

char	*ft_itoa_base(unsigned long n, int lower);

char	*ft_strprefix(char *prefix, char *str);

char	*ft_ptoa(long n);
#endif