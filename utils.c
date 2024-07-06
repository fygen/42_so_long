/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayegen <ayegen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 03:25:45 by ayegen            #+#    #+#             */
/*   Updated: 2024/07/06 16:19:09 by ayegen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(1);
}

int	strlen_y(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_map(char **map, char *msg)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	ft_error(msg);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	s = malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (i < ft_strlen(str))
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
