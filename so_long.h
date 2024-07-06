/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 21:00:14 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 16:19:06 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_xpm
{
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	char	*map;
}			t_xpm;

typedef struct s_state
{
	t_xpm	*img_paths;
	char	**map;
	int		x;
	int		y;
	int		collectiables;
	int		movement;
	int		exit[2];
	int		player[2];
	void	*mlx;
	void	*win;
}			t_state;

// Hook
int			deal_key(int key_code, t_state *screen);

// Map Func.
void		map_cord(char *map, t_state *data);
void		put_image(t_state *data, char **map, int i, int j);
void		assign_image(t_state *data);
void		read_map(t_state *data, char *map);
void		put_map(t_state *data);

// Map Check Func.
void		check_player(t_state *data, char **map);
void		check_map_chars(char **str);
void		check_exit(t_state *data, char **map);
void		col_check(t_state *data, char **map);
void		is_closed_map(char **map);
void		mapcheck(t_state *data);
void		arg_check(char *arg);

// Utils

void		ft_putnbr_fd(int n, int fd);
char		*ft_strdup(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		free_map(char **map, char *msg);
int			strlen_y(char **str);
void		ft_error(char *msg);
void		rectangular_check(char **map);

#endif
