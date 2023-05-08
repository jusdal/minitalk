/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:02:18 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/08 13:11:11 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c[11];
	int		i;

	nbr = n;
	i = 0;
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		c[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(c[i], fd);
}



int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);


}
