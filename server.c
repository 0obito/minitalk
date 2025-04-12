/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmsafe <aelmsafe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:38:22 by aelmsafe          #+#    #+#             */
/*   Updated: 2025/04/12 03:48:33 by aelmsafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bits_count;
	static pid_t			cid;
	static unsigned char	c;

	(void)context;
	if (cid != info->si_pid)
	{
		cid = info->si_pid;
		bits_count = 0;
	}
	if (signum == SIGUSR1)
		c = c >> 1;
	else if (signum == SIGUSR2)
		c = c >> 1 | 128;
	if (++bits_count == 8 && c == '\0')
		kill(info->si_pid, SIGUSR2);
	else
	{
		if (bits_count == 8)
		{
			write(1, &c, 1);
			bits_count = 0;
		}
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int ac, char *av[])
{
	pid_t					pid;
	struct sigaction		sa;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("Incorrect input!\nTry: ./server\n");
		exit(1);
	}
	pid = getpid();
	ft_putstr("Process ID: ");
	ft_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
