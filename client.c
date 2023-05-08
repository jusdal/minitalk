/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaly <jdaly@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:02:39 by jdaly             #+#    #+#             */
/*   Updated: 2023/05/08 19:47:17 by jdaly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

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

int	ft_atoi(const char *str)
{
	int	holder;
	int	minuscounter;
	int	i;

	i = 0;
	minuscounter = 1;
	holder = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minuscounter = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		holder = holder * 10 + (str[i] - '0');
		i++;
	}
	return (holder * minuscounter);
}

void	sendcharbybit(int pid, char c)
{
	int	bitcount;

	bitcount = 7;
	while (bitcount >= 0)
	{
		if ((c >> bitcount) & 1)
			kill(pid, SIGUSR1);
			//printf("SIGUSR1 PID: %d\n", pid);
		else
			kill(pid, SIGUSR2);
			//printf("SIGUSR2 PID %d\n", pid);
		usleep(125);
		bitcount--;
	}
	//convert char bit by bit and send SIGUSR1 or 2
}

int	main(int argc, char* argv[])
{
	int i;

	i = 0;
	if (argc != 3)
		ft_putstr_fd("Please follow this format: ./client <ServerPID> <message>\n", 1);
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			sendcharbybit(ft_atoi(argv[1]), argv[2][i]);
			i++;
		}
	}
}
