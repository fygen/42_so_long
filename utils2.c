/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 04:34:27 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 16:19:11 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = '0' + n;
		write(1, &c, 1);
	}
}

void	rectangular_check(char **map)
{
	int	len;
	int	i;
	int	x;

	len = 0;
	while (map[0][len] != '\n' && map[0][len])
		len++;
	i = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x] != '\n' && map[i][x])
			x++;
		if (len != x)
			free_map(map, "The map isn't rectangular!");
		i++;
	}
}
