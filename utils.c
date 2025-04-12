/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmsafe <aelmsafe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 03:26:40 by aelmsafe          #+#    #+#             */
/*   Updated: 2025/04/12 03:26:43 by aelmsafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	if (!str)
		string_error();
	i = 0;
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	c = n % 10 + '0';
	if (n / 10 == 0)
	{
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(n / 10);
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	if (str == NULL || str[0] == '\0')
		process_error();
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+')
		i++;
	if (!str[i] || str[i] > '9' || str[i] < '0')
		process_error();
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 4194304)
			process_error();
		i++;
	}
	while (str[i] == 32 || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i])
		process_error();
	return (res);
}

void	process_error(void)
{
	ft_putstr("Error! Process not found.\n");
	exit(1);
}

void	string_error(void)
{
	ft_putstr("String error!\n");
	exit(1);
}
