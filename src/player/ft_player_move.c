/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:43:19 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:09:46 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_move_player_right(t_map *mp, t_point point)
{
	char	**map;

	map = mp->matrix;
	if (map[point.x][point.y + 1] != '1')
	{
		if ((map[point.x][point.y + 1] == 'E' && mp->items.jaba > 0))
			return ;
		if (map[point.x][point.y + 1] == 'V' || map[point.x][point.y
			+ 1] == 'H')
			mp->cubou = 1;
		map[point.x][point.y] = '0';
		map[point.x][point.y + 1] = 'P';
		mp->steps++;
	}
}

void	ft_move_player_left(t_map *mp, t_point point)
{
	char	**map;

	map = mp->matrix;
	if (map[point.x][point.y - 1] != '1')
	{
		if ((map[point.x][point.y - 1] == 'E' && mp->items.jaba > 0))
			return ;
		if (map[point.x][point.y - 1] == 'V' || map[point.x][point.y
			- 1] == 'H')
			mp->cubou = 1;
		map[point.x][point.y] = '0';
		map[point.x][point.y - 1] = 'P';
		mp->steps++;
	}
}

void	ft_move_player_top(t_map *mp, t_point point)
{
	char	**map;

	map = mp->matrix;
	if (map[point.x - 1][point.y] != '1')
	{
		if ((map[point.x - 1][point.y] == 'E' && mp->items.jaba > 0))
			return ;
		if (map[point.x - 1][point.y] == 'V' || map[point.x
			- 1][point.y] == 'H')
			mp->cubou = 1;
		map[point.x][point.y] = '0';
		map[point.x - 1][point.y] = 'P';
		mp->steps++;
	}
}

void	ft_move_player_down(t_map *mp, t_point point)
{
	char	**map;

	map = mp->matrix;
	if (map[point.x + 1][point.y] != '1')
	{
		if ((map[point.x + 1][point.y] == 'E' && mp->items.jaba > 0))
			return ;
		if (map[point.x + 1][point.y] == 'V' || map[point.x
			+ 1][point.y] == 'H')
			mp->cubou = 1;
		map[point.x][point.y] = '0';
		map[point.x + 1][point.y] = 'P';
		mp->steps++;
	}
}
