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

#include "header.h"

void	ack_sig(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr("Message well received!\n");
}

void	send_char(pid_t pid, unsigned char c)
{
	int					i;
	int					bit;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = ack_sig;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	while (i < 8)
	{
		bit = (int)c % 2;
		c /= 2;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1))
				process_error();
		}
		else
			if (kill(pid, SIGUSR2))
				process_error();
		i++;
		usleep(500);
	}
}

void	send_str(pid_t pid, char *str)
{
	int	i;

	if (str == NULL)
		string_error();
	i = 0;
	while (str[i])
	{
		send_char(pid, (unsigned char)str[i]);
		i++;
	}
	send_char(pid, (unsigned char)str[i]);
}

int	main(int ac, char *av[])
{
	pid_t	pid;
	char	*str;

	if (ac != 3)
	{
		ft_putstr("Incorrect input!\nTry: ./client [server_pid] [string]\n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	send_str(pid, str);
	return (0);
}
