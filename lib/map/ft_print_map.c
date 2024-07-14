/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:31 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 20:53:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_print_map(stringg line, t_map map, t_point p, bool animation)
{
	int			i;
	void		*ig;
	t_objects	it;

	it = map.obs;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '1')
			ig = ft_put_image(map.win, it.block, map.igw, map.igh + 1, p.x,
					p.y);
		else if (line[i] == '0')
			ig = ft_put_image(map.win, it.empty, map.igw, map.igh, p.x, p.y);
		else if (line[i] == 'C')
			ig = ft_put_image(map.win, it.jaba, map.igw, map.igh, p.x, p.y);
		else if (line[i] == 'P')
			ig = ft_put_image(map.win, it.player, map.igw, map.igh, p.x, p.y);
		else if (line[i] == 'E')
			ig = ft_put_image(map.win, it.exit, map.igw, map.igh, p.x, p.y);
		p.x += map.igw + 2;
		if (animation)
			usleep(5500);
		ft_destroy_image(map.win, ig);
	}
}
