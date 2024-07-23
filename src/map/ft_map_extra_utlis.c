/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_extra_utlis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:16:18 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 13:41:01 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_point	ft_find_char(char **map, char ch)
{
	t_point	point;

	point.x = 0;
	point.y = 0;
	while (map[point.x])
	{
		point.y = 0;
		while (map[point.x][point.y] && map[point.x][point.y] != ch)
			point.y++;
		if (map[point.x][point.y] == ch)
			return (point);
		point.x++;
	}
	point = (t_point){-1, -1};
	return (point);
}
