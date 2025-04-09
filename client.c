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

int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		printf("Process ID received: %s\n", av[1]);
		if (1)
		{
			printf("%s\n", av[2]);
		}
	}
	return (0);
}
