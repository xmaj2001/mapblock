/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 06:08:39 by xjose             #+#    #+#             */
/*   Updated: 2024/07/21 06:44:15 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_extra(char **map, t_size size, t_point p)
{
	if (map[size.height - 1][p.y] != '1' && map[size.height - 1][p.y] != '\n')
		return (FALSE);
	else
		return (TRUE);
}

static int	ft_map_is_surrounded_wall(char **map)
{
	t_point	p;
	t_size	size;

	p = (t_point){0, 1};
	size = ft_get_size_map(map);
	while (map[0][p.y])
	{
		if (map[0][p.y] != '1' && map[0][p.y] != '\n')
			return (FALSE);
		p.y++;
	}
	while (map[p.x] && p.x < size.height)
	{
		if (map[p.x][0] != '1' || map[p.x][size.width - 1] != '1')
			return (FALSE);
		p.x++;
	}
	p.y = 0;
	while (map[size.height - 1][p.y])
	{
		if (ft_extra(map, size, p) == FALSE)
			return (FALSE);
		p.y++;
	}
	return (TRUE);
}

int	ft_validate_map(char **map, t_items items)
{
	if (ft_check_width(map) == FALSE)
	{
		ft_printf("Error\nA LARGURA DO MAPA ESTÁ INCORRETA\n");
		return (FALSE);
	}
	if (ft_map_is_surrounded_wall(map) == FALSE)
	{
		ft_printf("Error\nO MAPA NÃO ESTÁ COMPLETAMENTE CERCADO DE PAREDES.\n");
		return (FALSE);
	}
	else if (ft_is_rectangle(ft_get_size_map(map)) == FALSE)
	{
		ft_printf("Error\nO MAPA NÃO É RETANGULAR\n");
		return (FALSE);
	}
	else if (ft_number_items_is_validate(items) == FALSE)
	{
		ft_printf("Error\nO MAPA NÃO TEM ");
		ft_printf("O NÚMERO DE ITENS NECESSÁRIOS\n");
		return (FALSE);
	}
	else
		return (ft_items_required(map));
}
