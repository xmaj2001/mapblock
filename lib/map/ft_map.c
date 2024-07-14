/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:52:07 by xjose             #+#    #+#             */
/*   Updated: 2024/07/14 14:58:44 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*ft_get_map(int fd, t_map *tmap)
{
	char	*str_map;

	if (fd < 0)
	{
		ft_printf("ERRO FD INVALIDE\n");
		return (NULL);
	}
	str_map = ft_read_map(fd);
	if (ft_strlen(str_map) == 0)
	{
		ft_printf("MAP EMPTEY\n");
		return (NULL);
	}
	tmap->map = ft_split(str_map, '\n');
	ft_get_item_map(tmap);
	if (ft_validate_map(tmap->map, tmap->items))
		return (tmap);
	return (NULL);
}

t_map	*ft_load_map(t_window *win, t_map *map)
{
	map->win = win;
	ft_get_item_map(map);
	return (map);
}
