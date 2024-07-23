/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 16:52:07 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 14:56:23 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_print_line(char *line, t_map m, t_point p, int animation)
{
	int			i;
	void		*ig;
	t_size		size;
	t_path_imgs	it;

	it = m.paths;
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
		else if (line[i] == 'V')
			ig = ft_put_image(m.win, it.ghost, size, p);
		p.x += m.igw + 2;
		if (animation)
			usleep(5500);
		ft_destroy_image(m.win, ig);
	}
}

void	ft_print_map(t_map map, enum e_postion postion, int animation)
{
	t_point	point;
	t_point	ps;
	t_size	size;
	int		i;

	size = ft_get_size_map(map.matrix);
	size.width *= map.igw;
	i = 0;
	size.height *= map.igh;
	ps = ft_postion(map.win, size, postion);
	point.y = ps.y;
	while (map.matrix[i])
	{
		point.x = ps.x;
		ft_print_line(map.matrix[i], map, point, animation);
		i++;
		point.y += map.igh + 2;
	}
}
