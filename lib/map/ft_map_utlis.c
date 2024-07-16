/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:16:18 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 13:52:42 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

char	*ft_read_map(int fd)
{
	static char	buffer;
	char		map[4024];
	int			read_size;
	int			x;

	x = 0;
	while (x < 4024)
		map[x++] = '\0';
	x = 0;
	read_size = 1;
	while (1)
	{
		read_size = read(fd, &buffer, 1);
		if (read_size == 0)
			break ;
		map[x] = buffer;
		x++;
	}
	map[x] = '\0';
	return (ft_strdup(map));
}

void	ft_get_item_map(t_map *map)
{
	map->items.jaba = ft_count_item(map->map, 'C');
	map->items.player = ft_count_item(map->map, 'P');
	map->items.exit = ft_count_item(map->map, 'E');
	map->items.block = ft_count_item(map->map, '1');
	map->items.empty = ft_count_item(map->map, '0');
}

int	ft_count_item(char **map, char item)
{
	t_point	point;
	int		i;

	point.y = 0;
	i = 0;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x])
		{
			if (map[point.y][point.x] == item)
				i++;
			point.x++;
		}
		point.y++;
	}
	return (i);
}
