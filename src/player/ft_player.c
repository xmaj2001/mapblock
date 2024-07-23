/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:18:15 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 14:37:58 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_player_move(t_map *mp, int move, char *imag_move)
{
	t_point	point;
	char	**map;

	point.x = 0;
	map = mp->matrix;
	point = ft_find_char(map, 'P');
	if(point.x < 0)
		return ;
	if (move == 1)
		ft_move_player_right(mp, point);
	else if (move == 2)
		ft_move_player_top(mp, point);
	else if (move == 3)
		ft_move_player_left(mp, point);
	else if (move == 4)
		ft_move_player_down(mp, point);
	mp->paths.player = imag_move;
}
