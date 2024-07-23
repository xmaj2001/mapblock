/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:15 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:20:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_enemy_move(t_map *mp)
{
	static int	move;
	t_point		point;
	char		**map;

	map = mp->matrix;
	point = ft_find_char(map, 'V');
	if(point.x < 0)
		return ;
	if (move == 1 && map[point.x + 1][point.y] == '1')
		move = 0;
	else if (move == 0 && map[point.x - 1][point.y] == '1')
		move = 1;
	if (move == 1)
	{
		map[point.x][point.y] = '0';
		map[point.x + 1][point.y] = 'V';
	}
	else
	{
		map[point.x][point.y] = '0';
		map[point.x - 1][point.y] = 'V';
	}
	
}
