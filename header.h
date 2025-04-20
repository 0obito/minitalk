/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelmsafe <aelmsafe@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 03:26:57 by aelmsafe          #+#    #+#             */
/*   Updated: 2025/04/12 03:27:00 by aelmsafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	process_error(void);
void	string_error(void);

#endif /* HEADER_H */
