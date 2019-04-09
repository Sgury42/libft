/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:18:28 by sgury             #+#    #+#             */
/*   Updated: 2019/04/08 18:44:57 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;

	if (n < 0)
	{
		write(fd,"-", 1);
		if (n == -2147483648)
			write(fd, "-2147483648", 11);
		n *= -1;
	}
	if (n < 10)
	{
		nbr = n + '0';
		write(fd, &nbr, 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		nbr = n % 10 + '0';
		write(fd, &nbr, 1);
	}
}