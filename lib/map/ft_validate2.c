/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:39:22 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 17:05:41 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

int	ft_plus(char **map, t_size size, t_point p)
{
	if (map[size.height - 1][p.x] != '1' && map[size.height - 1][p.x] != '\n')
		return (FALSE);
	else
		return (TRUE);
}

static int	ft_is_valide_width2(char **map)
{
	t_point	p;
	t_size	size;

	p = (t_point){1, 0};
	size = ft_get_size_map(map);
	while (map[0][p.x])
	{
		if (map[0][p.x] != '1' && map[0][p.x] != '\n')
			return (FALSE);
		p.x++;
	}
	while (map[p.y] && p.y < size.height)
	{
		if (map[p.y][0] != '1' || map[p.y][size.width - 1] != '1')
			return (FALSE);
		p.y++;
	}
	p.x = 0;
	while (map[size.height - 1][p.x])
	{
		if (ft_plus(map, size, p) == FALSE)
			return (FALSE);
		p.x++;
	}
	return (TRUE);
}

int	ft_validate_map(char **map, t_items items)
{
	if (ft_is_valide_width(map) == FALSE)
	{
		ft_printf("Error\nA LARGURA DO MAPA ESTÁ INCORRETA\n");
		return (FALSE);
	}
	if (ft_is_valide_width2(map) == FALSE)
	{
		ft_printf("Error\nO MAPA NÃO ESTÁ COMPLETAMENTE CERCADO DE PAREDES.\n");
		return (FALSE);
	}
	else if (ft_is_rectangle(ft_get_size_map(map)) == FALSE)
	{
		ft_printf("Error\nO MAPA NÃO É RETANGULAR\n");
		return (FALSE);
	}
	else if (ft_is_valide_items(items) == FALSE)
	{
		ft_printf("Error\nO MAPA NÃO CONTA ");
		ft_printf("O NÚMERO DE ITENS NECESSÁRIOS\n");
		return (FALSE);
	}
	else
	{
		return (ft_items_required(map));
	}
}

static void	ft_ms_error(char *path)
{
	ft_printf("Error\n");
	ft_printf("MAPA INVÁLIDO\ncaminho: %s \n", path);
	exit(1);
}

int	ft_open_map(char *path)
{
	size_t	len;
	int		fd;
	char	*extension;

	len = ft_strlen(path);
	fd = 0;
	if (len == 0 || len <= 4)
		ft_ms_error(path);
	else
	{
		extension = ft_substr(path, len - 4, len - 1);
		if (ft_strncmp(extension, ".ber", 4))
			ft_ms_error(path);
		fd = open(path, 0);
		if (fd < 0)
			ft_ms_error(path);
	}
	return (fd);
}
