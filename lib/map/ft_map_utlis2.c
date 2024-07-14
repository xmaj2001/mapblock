/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utlis2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 18:45:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/14 18:29:52 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_size	ft_get_size_map_win(char **map, int size_img)
{
	t_size	size;
	int		i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]) * size_img + 400;
	size.height = i * size_img + 400;
	return (size);
}

t_size	ft_get_size_map(char **map)
{
	t_size	size;
	int		i;

	i = 0;
	while (map[i])
		i++;
	size.width = ft_strlen(map[0]);
	size.height = i;
	return (size);
}
