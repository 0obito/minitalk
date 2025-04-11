/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmsafe <aelmsafe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:38:42 by aelmsafe          #+#    #+#             */
/*   Updated: 2025/04/09 01:38:45 by aelmsafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	if (str == NULL || str[0] == '\0')
		exit(1);
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i])
		exit(1);
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res > 4194304)
			exit(1);
	}
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i])
		exit(1);
	return (res);
}

void	ack_sig(int signum)
{
	if (signum == SIGUSR1)
		return ;
}

void	send_char(pid_t pid, unsigned char c)
{
	struct sigaction	sa;
	int					i;
	int					bit;

	sa.sa_flags = 0;
	sa.sa_handler = ack_sig;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	i = 0;
	while (i < 8)
	{
		bit = (int)c % 2;
		c /= 2;
		if (bit == 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		i++;
		pause();
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	if (str == NULL)
		exit(1);
	i = 0;
	while (str[i])
	{
		send_char(pid, (unsigned char)str[i]);
		i++;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	char	*str;

	if (ac != 3)
	{
		printf("Incorrect input!\nTry: ./client [server_pid] [string]");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	send_str(pid, str);
	return (0);
}
