/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 20:35:44 by kbraum            #+#    #+#             */
/*   Updated: 2020/12/18 20:27:37 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(long n, int fd)
{
	int		i;
	long	m;
	char	c;

	m = 1;
	i = 0;
	while (n / m > 9 || n / m < -9)
		m *= 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		m *= -1;
	}
	while (m != 0)
	{
		c = n / m % 10 + '0';
		i += write(fd, &c, 1);
		m /= 10;
	}
	return (i);
}
