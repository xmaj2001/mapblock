/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:16 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 20:47:02 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_player
{
	int	stepd;
}		t_player;

char	ft_move_player_right(t_map *mp, t_point point);
char	ft_move_player_left(t_map *mp, t_point point);
char	ft_move_player_top(t_map *mp, t_point point);
char	ft_move_player_down(t_map *mp, t_point point);
char	**ft_find_player(t_map *mp, int move);