/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschmid <fschmid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:17:52 by fschmid           #+#    #+#             */
/*   Updated: 2022/10/30 14:46:44 by fschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int	ft_p(char *str, int is_s_flag);
int	ft_print_char(char c);


int		ft_is_flag(char c);

char	*ft_itoa_base(unsigned long n, int lower);

char	*ft_strprefix(char *prefix, char *str);

char	*ft_ptoa(long n);
#endif