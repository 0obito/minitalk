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

// unsigned char	g_byte = 0;
static unsigned char	byte = 0;

void	handle_sigusr1(int signum)
{
	byte << 1;

}

void	handle_sigusr2(int signum)
{
	byte << 1;
}

// void	handle_signal(int signum)
// {
// 	if (signum == SIGUSR1)
// 	{
// 		printf("SIGUSR1\n");
// 	}
// 	else if (signum == SIGUSR2)
// 	{
// 		printf("SIGUSR2\n");
// 	}
// 	// else
// 	// 	; //	temporarily, until I have an idea what to do here!
// }

int	main(void)
{
	pid_t				pid;
	struct sigaction	act1;
	struct sigaction	act2;

	//	Get and print the current process' id:
	pid = getpid();
	printf("%d\n", pid);
	//	Fill structures act1:
	act1.sa_handler = handle_sigusr1;
	sigemptyset(&act1.sa_mask);
	act1.sa_flags = 0;	//there's SA_SIGINFO as well, need to look it up!
	//	Fill structures act2:
	act2.sa_handler = handle_sigusr2;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = 0;	//there's SA_SIGINFO as well, need to look it up!
	//	handle the signal SIGUSR1:
	if (sigaction(SIGUSR1, &act1, NULL) == -1)
		exit(1);
	//	handle the signal SIGUSR2:
	if (sigaction(SIGUSR2, &act2, NULL) == -1)
		exit(1);
	//	waiting loop for a signal
	while (1)
	{
		pause();
	}
	return (0);
}
