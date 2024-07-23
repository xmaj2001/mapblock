/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 06:08:39 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 14:25:07 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_check_width(char **map)
{
	t_size	size;
	size_t	width;
	int		p;

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

int	ft_number_items_is_validate(t_items item)
{
	if (item.player == 1 && item.jaba >= 1 && item.exit == 1 && item.block >= 1
		&& item.empty >= 1)
		return (TRUE);
	else
		return (FALSE);
}

static int	ft_is_valid_char(char ch)
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
	else if (ch == 'V')
		return (TRUE);
	else
		return (FALSE);
}

int	ft_items_required(char **map)
{
	t_point p;

	p = (t_point){0, 0};
	while (map[p.x])
	{
		p.y = 0;
		while (map[p.x][p.y])
		{
			if (!ft_is_valid_char(map[p.x][p.y]))
			{
				ft_printf("Error valores inválidos encontrados no map\n");
				return (FALSE);
			}
			p.y++;
		}
		p.x++;
	}
	return (TRUE);
}
