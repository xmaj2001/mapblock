/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 05:46:51 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:11:40 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_set_item_map(t_map *map)
{
	map->items.jaba = ft_count_item(map->matrix, 'C');
	map->items.player = ft_count_item(map->matrix, 'P');
	map->items.exit = ft_count_item(map->matrix, 'E');
	map->items.block = ft_count_item(map->matrix, '1');
	map->items.empty = ft_count_item(map->matrix, '0');
	map->items.ghost = ft_count_item(map->matrix, 'V');
}

t_map	*ft_get_map(int fd, t_map *tmap)
{
	char	*str_map;

	if (fd < 0)
	{
		ft_printf("ERRO FD INVALIDE\n");
		return (NULL);
	}
	str_map = ft_read_file_map(fd);
	if (ft_strlen(str_map) == 0)
	{
		ft_printf("MAP EMPTEY\n");
		return (NULL);
	}
	tmap->matrix = ft_split(str_map, '\n');
	ft_set_item_map(tmap);
	if (ft_validate_map(tmap->matrix, tmap->items))
		return (tmap);
	return (NULL);
}

void	ft_set_maps(t_map *g_map)
{
	g_map->maps[0] = ft_strdup("./maps/map.ber");
	g_map->maps[1] = ft_strdup("./maps/map1.ber");
	g_map->maps[2] = ft_strdup("./maps/map2.ber");
	g_map->maps[3] = ft_strdup("./maps/map3.ber");
	g_map->maps[4] = ft_strdup("./maps/map4.ber");
	g_map->maps[5] = ft_strdup("./maps/map5.ber");
}

void	ft_init_map(t_window *win, t_map *g_map)
{
	g_map->win = win;
	g_map->move = 0;
	g_map->cubou = 0;
	g_map->paths.empty = "./assets/0.xpm";
	g_map->paths.block = "./assets/1.xpm";
	g_map->paths.exit = "./assets/E.xpm";
	g_map->paths.player = "./assets/player/PW.xpm";
	g_map->paths.jaba = "./assets/C.xpm";
	g_map->paths.ghost = "./assets/I.xpm";
	g_map->igh = 40;
	g_map->igw = 40;
}
