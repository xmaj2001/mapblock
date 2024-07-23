/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utlis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:16:18 by xjose             #+#    #+#             */
/*   Updated: 2024/07/21 05:52:20 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

int	ft_open_map(char *path)
{
	size_t	len;
	int		fd;
	char	*extension;

	len = ft_strlen(path);
	fd = 0;
	if (len == 0 || len <= 4)
		ft_printf("Erro\n");
	else
	{
		extension = ft_substr(path, len - 4, len - 1);
		if (ft_strncmp(extension, ".ber", 4))
			ft_printf("Erro\n");
		fd = open(path, 0);
		if (fd < 0)
			ft_printf("Erro\n");
	}
	return (fd);
}

char	*ft_read_file_map(int fd)
{
	char	buffer;
	char	map[4024];
	int		read_size;
	int		x;

	ft_bzero(map, 4024);
	x = 0;
	read_size = 1;
	while (1)
	{
		read_size = read(fd, &buffer, 1);
		if (read_size < 0)
			return (NULL);
		if (read_size == 0)
			break ;
		map[x] = buffer;
		x++;
	}
	map[x] = '\0';
	return (ft_strdup(map));
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

t_size	ft_get_size_map_win(char **map, int size_img)
{
	t_size	size;
	int		i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]) * size_img + 400;
	size.height = i * size_img + 400;
	return (size);
}

t_size	ft_get_size_map(char **map)
{
	t_size	size;
	int		i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]);
	size.height = i;
	return (size);
}
