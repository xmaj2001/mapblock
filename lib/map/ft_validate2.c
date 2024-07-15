/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:39:22 by xjose             #+#    #+#             */
/*   Updated: 2024/07/15 18:52:10 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

static bool	ft_is_valide_width2(char **map)
{
	t_point	p;
	t_size	size;

	p = (t_point){1, 0};
	size = ft_get_size_map(map);
	while (map[0][p.x])
	{
		if (map[0][p.x] != '1' && map[0][p.x] != '\n')
			return (false);
		p.x++;
	}
	while (map[p.y] && p.y < size.height)
	{
		if (map[p.y][0] != '1' || map[p.y][size.width - 1] != '1')
			return (false);
		p.y++;
	}
	p.x = 0;
	while (map[size.height - 1][p.x])
	{
		if (map[size.height - 1][p.x] != '1' && map[size.height
			- 1][p.x] != '\n')
			return (false);
		p.x++;
	}
	return (true);
}

bool	ft_validate_map(char **map, t_items items)
{
	if (ft_is_valide_width(map) == false)
	{
		ft_printf("Error\nTHE WIDTH OF THE MAP IS INCORRECT\n");
		return (false);
	}
	if (ft_is_valide_width2(map) == false)
	{
		ft_printf("Error\nTHE MAP IS NOT COMPLETELY SURROUNDED WITH WALLS.\n");
		return (false);
	}
	else if (ft_is_rectangle(ft_get_size_map(map)) == false)
	{
		ft_printf("Error\nTHE MAP IS NOT RECTANGULAR\n");
		return (false);
	}
	else if (ft_is_valide_items(items) == false)
	{
		ft_printf("Error\nTHE MAP DOES NOT COUNT THE NUMBER OF REQUIRED ITEMS\n");
		return (false);
	}
	else
	{
		return (ft_items_required(map));
	}
}

static void	ft_ms_error(stringg path)
{
	ft_printf("Error\n");
	ft_printf("INVALID MAP\npath: %s \n", path);
	exit(1);
}

int	ft_open_map(stringg path)
{
	size_t	len;
	int		fd;
	char	*extension;

	len = ft_strlen(path);
	fd = 0;
	if (len == 0 || len <= 4)
		ft_ms_error(path);
	else
	{
		extension = ft_substr(path, len - 4, len - 1);
		if (ft_strncmp(extension, ".ber", 4))
			ft_ms_error(path);
		fd = open(path, 0);
		if (fd < 0)
			ft_ms_error(path);
	}
	return (fd);
}
