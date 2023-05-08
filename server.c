/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:02:18 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/08 16:31:46 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
//#include <stdio.h>
//#include <stdlib.h>

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

void sighandler(int signum)
{
	/*if (signum == SIGUSR1 || signum == SIGUSR2)
		ft_putstr_fd("SIGNAL CAUGHT", 1);*/

	static int	bitcount = 0;
	static int	c = 0;

	if (signum == SIGUSR1)
		c |= 1; // sets right bit to 1
		//ft_putstr_fd("SIGUSR1 RECEIVED", 1);
	bitcount++;
	if (bitcount == 8) // checks if 8 bits and prints
	{
		ft_putchar_fd(c, 1);
		bitcount = 0;
		c = 0;
	}
	else
		c <<= 1; // shifts bits left by 1, adding a 0 on the right
		//ft_putstr_fd("ELSE", 1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server PID = ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);

	while (1) // listen for signals
	{
		signal(SIGUSR1, sighandler);
		signal(SIGUSR2, sighandler);
	}
	return (0);
}
