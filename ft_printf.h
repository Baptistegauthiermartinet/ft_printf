/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:03:11 by bgauthie          #+#    #+#             */
/*   Updated: 2022/12/16 11:32:07 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putnbr_base_fd(long long nbr, char *base, int *printed, int fd);
void	ft_putptr_fd(void *ptr, char *base, int *printed, int fd);
void	ft_putchar_fd(char c, int *printed, int fd);
void	ft_putstr_fd(char *s, int *printed, int fd);
size_t	ft_strlen(const char *s);

int		ft_printf(const char *str, ...);
void	get_type(const char *str, va_list a, size_t *i, int *printed);

#endif