/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:15 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 20:51:04 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**ft_find_player(t_map *mp, int move)
{
	t_point	point;
	char	**map;

	point.y = 0;
	map = mp->map;
	while (map[point.y])
	{
		point.x = 0;
		while (map[point.y][point.x] && map[point.y][point.x] != 'P')
			point.x++;
		if (map[point.y][point.x] == 'P')
		{
			if (move == 1)
				map[point.y][point.x] = ft_move_player_right(mp, point);
			else if (move == 2)
				map[point.y][point.x] = ft_move_player_top(mp, point);
			else if (move == 3)
				map[point.y][point.x] = ft_move_player_left(mp, point);
			else if (move == 4)
				map[point.y][point.x] = ft_move_player_down(mp, point);
			break ;
		}
		point.y++;
	}
	return (map);
}
