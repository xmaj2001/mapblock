/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:09:31 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 16:59:12 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_print_map(char *line, t_map m, t_point p, int animation)
{
	int			i;
	void		*ig;
	t_size		size;
	t_objects	it;

	it = m.obs;
	i = -1;
	while (line[++i])
	{
		size = (t_size){m.igw, m.igh};
		if (line[i] == '1')
			ig = ft_put_image(m.win, it.block, (t_size){m.igw, m.igh + 1}, p);
		else if (line[i] == '0')
			ig = ft_put_image(m.win, it.empty, size, p);
		else if (line[i] == 'C')
			ig = ft_put_image(m.win, it.jaba, size, p);
		else if (line[i] == 'P')
			ig = ft_put_image(m.win, it.player, size, p);
		else if (line[i] == 'E')
			ig = ft_put_image(m.win, it.exit, size, p);
		p.x += m.igw + 2;
		if (animation)
			usleep(5500);
		ft_destroy_image(m.win, ig);
	}
}
