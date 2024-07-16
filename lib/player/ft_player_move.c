/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:43:19 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 16:17:57 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	ft_move_player_right(t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y][point.x + 1] != '1')
	{
		if (map[point.y][point.x + 1] == 'E' && mp->items.jaba == 0)
			ft_close_window(mp->win);
		else if (map[point.y][point.x + 1] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y][point.x + 1] = 'P';
			mp->steps++;
		}
	}
	return (map[point.y][point.x]);
}

char	ft_move_player_left(t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y][point.x - 1] != '1')
	{
		if (map[point.y][point.x - 1] == 'E' && mp->items.jaba == 0)
			ft_close_window(mp->win);
		else if (map[point.y][point.x - 1] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y][point.x - 1] = 'P';
			mp->steps++;
		}
	}
	return (map[point.y][point.x]);
}

char	ft_move_player_top(t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y - 1][point.x] != '1')
	{
		if (map[point.y - 1][point.x] == 'E' && mp->items.jaba == 0)
			ft_close_window(mp->win);
		else if (map[point.y - 1][point.x] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y - 1][point.x] = 'P';
			mp->steps++;
		}
	}
	return (map[point.y][point.x]);
}

char	ft_move_player_down(t_map *mp, t_point point)
{
	char	**map;

	map = mp->map;
	if (map[point.y + 1][point.x] != '1')
	{
		if (map[point.y + 1][point.x] == 'E' && mp->items.jaba == 0)
			ft_close_window(mp->win);
		else if (map[point.y + 1][point.x] != 'E')
		{
			map[point.y][point.x] = '0';
			map[point.y + 1][point.x] = 'P';
			mp->steps++;
		}
	}
	return (map[point.y][point.x]);
}
