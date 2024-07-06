/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:27:55 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 20:15:36 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_state *data)
{
	if (data->map[data->player[0] - 1][data->player[1]] != '1')
	{
		data->movement++;
		write(1, "Your Movement = ", 16);
		ft_putnbr_fd(data->movement, 1);
		write(1, "\n", 1);
		if (data->map[data->player[0] - 1][data->player[1]] == 'C')
			data->collectiables--;
		if (data->map[data->player[0] - 1][data->player[1]] == 'E'
			&& data->collectiables == 0)
		{
			write(1, "YOU WON THE GAME, SEE YOU!", 26);
			exit(0);
		}
		mlx_clear_window(data->mlx, data->win);
		data->map[data->player[0]][data->player[1]] = '0';
		data->map[data->player[0] - 1][data->player[1]] = '0';
		put_map(data);
		data->player[0] = data->player[0] - 1;
		data->map[data->player[0]][data->player[1]] = 'P';
	}
}

static void	move_down(t_state *data)
{
	if (data->map[data->player[0] + 1][data->player[1]] != '1')
	{
		data->movement++;
		write(1, "Your Movement = ", 16);
		ft_putnbr_fd(data->movement, 1);
		write(1, "\n", 1);
		if (data->map[data->player[0] + 1][data->player[1]] == 'C')
			data->collectiables--;
		if (data->map[data->player[0] + 1][data->player[1]] == 'E'
			&& data->collectiables == 0)
		{
			write(1, "YOU WON THE GAME, SEE YOU!", 26);
			exit(0);
		}
		mlx_clear_window(data->mlx, data->win);
		data->map[data->player[0]][data->player[1]] = '0';
		data->map[data->player[0] + 1][data->player[1]] = '0';
		put_map(data);
		data->player[0] = data->player[0] + 1;
		data->map[data->player[0]][data->player[1]] = 'P';
	}
}

static void	move_left(t_state *data)
{
	if (data->map[data->player[0]][data->player[1] - 1] != '1')
	{
		data->movement++;
		write(1, "Your Movement = ", 16);
		ft_putnbr_fd(data->movement, 1);
		write(1, "\n", 1);
		if (data->map[data->player[0]][data->player[1] - 1] == 'C')
			data->collectiables--;
		if (data->map[data->player[0]][data->player[1] - 1] == 'E'
			&& data->collectiables == 0)
		{
			write(1, "YOU WON THE GAME, SEE YOU!", 26);
			exit(0);
		}
		mlx_clear_window(data->mlx, data->win);
		data->map[data->player[0]][data->player[1]] = '0';
		data->map[data->player[0]][data->player[1] - 1] = '0';
		put_map(data);
		data->player[1] = data->player[1] - 1;
		data->map[data->player[0]][data->player[1]] = 'P';
	}
}

static void	move_right(t_state *data)
{
	if (data->map[data->player[0]][data->player[1] + 1] != '1')
	{
		data->movement++;
		write(1, "Your Movement = ", 16);
		ft_putnbr_fd(data->movement, 1);
		write(1, "\n", 1);
		if (data->map[data->player[0]][data->player[1] + 1] == 'C')
			data->collectiables--;
		if (data->map[data->player[0]][data->player[1] + 1] == 'E'
			&& data->collectiables == 0)
		{
			write(1, "YOU WON THE GAME, SEE YOU!", 26);
			exit(0);
		}
		mlx_clear_window(data->mlx, data->win);
		data->map[data->player[0]][data->player[1]] = '0';
		data->map[data->player[0]][data->player[1] + 1] = '0';
		put_map(data);
		data->player[1] = data->player[1] + 1;
		data->map[data->player[0]][data->player[1]] = 'P';
	}
}

int	deal_key(int key_code, t_state *data)
{
	if (key_code == 13)
		move_up(data);
	else if (key_code == 1)
		move_down(data);
	else if (key_code == 0)
		move_left(data);
	else if (key_code == 2)
		move_right(data);
	else if (key_code == 53)
		exit(0);
	if (data->player[0] == data->exit[0] && data->player[1] == data->exit[1])
	{
		mlx_clear_window(data->mlx, data->win);
		data->map[data->exit[0]][data->exit[1]] = 'E';
		put_map(data);
		data->map[data->exit[0]][data->exit[1]] = 'P';
	}
	else
		data->map[data->exit[0]][data->exit[1]] = 'E';
	put_map(data);
	return (0);
}
