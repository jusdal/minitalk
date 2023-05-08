/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:02:18 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/09 01:07:03 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

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

void	sigusrhandler(int signum)
{
	static int	bitcount = 1;
	static int	c = 0;

	if (signum == SIGUSR1)
		c |= 1;
	if (bitcount == 8)
	{
		ft_putchar_fd(c, 1);
		bitcount = 0;
		c = 0;
	}
	else
		c <<= 1;
	bitcount++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, sigusrhandler);
		signal(SIGUSR2, sigusrhandler);
	}
	return (0);
}
