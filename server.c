/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmsafe <aelmsafe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:38:22 by aelmsafe          #+#    #+#             */
/*   Updated: 2025/04/09 01:38:24 by aelmsafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int				bits_count;
	static unsigned char	c;

	(void)context;
	if (signum == SIGUSR1)
	{
		c = c >> 1;
	}
	else if (signum == SIGUSR2)
	{
		c = c >> 1 | 128;
	}
	bits_count += 1;
	if (bits_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bits_count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t					pid;
	struct sigaction		sa;

	pid = getpid();
	printf("Process ID: %d\n", pid);
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
