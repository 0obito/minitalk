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

int	main(void)
{
	int	pid;

	pid = getpid();
	printf("%d\n", pid);
	kill(pid, 0);
	return (0);
}
