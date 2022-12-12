/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgauthie <bgauthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:49:25 by bgauthie          #+#    #+#             */
/*   Updated: 2022/12/12 17:11:54 by bgauthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_fd(long long nbr, char *base, int *printed, int fd)
{
	long	size;

	size = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', printed, fd);
		nbr *= -1;
	}
	if (nbr < size)
		ft_putchar_fd(base[nbr], printed, fd);
	else
	{
		ft_putnbr_base_fd(nbr / size, base, printed, fd);
		ft_putchar_fd(base[nbr % size], printed, fd);
	}
}

void	ft_putptr_fd(void *ptr, char *base, int *printed, int fd)
{
	size_t	nbr;
	char	str[17];
	int		i;

	if (!ptr)
		ft_putstr_fd("0x0", printed, fd);
	else
		ft_putstr_fd("0x", printed, fd);
	nbr = (unsigned long)ptr;
	i = 0;
	while (nbr > 0)
	{
		str[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(str[i], printed, fd);
}

void	ft_putstr_fd(char *s, int *printed, int fd)
{
	size_t	i;

	if (!s)
	{
		ft_putstr_fd("(null)", printed, fd);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], printed, fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int *printed, int fd)
{
	if (*printed == -1)
		return ;
	if (write(fd, &c, 1) == -1)
		*printed = -1;
	else
		*printed += 1;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
