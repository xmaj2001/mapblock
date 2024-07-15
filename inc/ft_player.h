/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:16 by xjose             #+#    #+#             */
/*   Updated: 2024/07/15 18:37:19 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PLAYER_H

# define FT_PLAYER_H
typedef struct s_player
{
	int	stepd;
}		t_player;

char	ft_move_player_right(t_map *mp, t_point point);
char	ft_move_player_left(t_map *mp, t_point point);
char	ft_move_player_top(t_map *mp, t_point point);
char	ft_move_player_down(t_map *mp, t_point point);
char	**ft_find_player(t_map *mp, int move);

#endif