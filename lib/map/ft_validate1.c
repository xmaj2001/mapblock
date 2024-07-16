/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:34:35 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 17:05:49 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_is_valide_width(char **map)
{
	int		p;
	t_size	size;
	size_t	width;

	size = ft_get_size_map(map);
	width = size.width;
	p = 0;
	while (map[p])
	{
		if (ft_strlen(map[p]) != width)
			return (FALSE);
		p++;
	}
	return (TRUE);
}

int	ft_is_rectangle(t_size size)
{
	return ((size.width > size.height) || (size.width < size.height));
}

int	ft_is_valide_char(char ch)
{
	if (ch == '0')
		return (TRUE);
	else if (ch == '1')
		return (TRUE);
	else if (ch == 'C')
		return (TRUE);
	else if (ch == 'E')
		return (TRUE);
	else if (ch == 'P')
		return (TRUE);
	else if (ch == '\n')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_is_valide_items(t_items item)
{
	if (item.player == 1 && item.jaba >= 1 && item.exit == 1 && item.block >= 1
		&& item.empty >= 1)
		return (TRUE);
	else
		return (FALSE);
}

int	ft_items_required(char **map)
{
	t_point	p;

	p = (t_point){0, 0};
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (!ft_is_valide_char(map[p.y][p.x]))
			{
				ft_printf("Error\n");
				return (FALSE);
			}
			p.x++;
		}
		p.y++;
	}
	return (TRUE);
}
