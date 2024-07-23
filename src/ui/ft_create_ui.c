/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_ui.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:21:48 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 12:35:15 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_create_menu(t_window *window, t_menu *tmenu)
{
	t_size	size;
	t_point	point;

	point = ft_postion(window, (t_size){200, 208}, CENTER);
	free(ft_put_image(window, tmenu->background, (t_size){200, 208}, point));
	point = ft_postion(window, (t_size){170, 130}, CENTER);
	free(ft_put_image(window, tmenu->btn_play, (t_size){170, 44}, point));
	point = ft_postion(window, (t_size){170, 30}, CENTER);
	free(ft_put_image(window, tmenu->btn_exit, (t_size){170, 44}, point));
	point = ft_postion(window, (t_size){151, -90}, CENTER);
	free(ft_put_image(window, tmenu->xjose, (t_size){151, 30}, point));
	point = ft_postion(window, (t_size){200, 500}, CENTER);
	free(ft_put_image(window, tmenu->title, (t_size){200, 50},
			point));
}

void	ft_create_ui_map(t_window *window, t_menu_map *tmenu)
{
	t_size	size;
	t_point	point;

	point = ft_postion(window, (t_size){739, 400}, CENTER);
	free(ft_put_image(window, tmenu->background, (t_size){739, 400}, point));
	point = ft_postion(window, (t_size){639, 315}, CENTER);
	free(ft_put_image(window, tmenu->map0, (t_size){200, 150}, point));
	point = ft_postion(window, (t_size){200, 315}, CENTER);
	free(ft_put_image(window, tmenu->map1, (t_size){200, 150}, point));
	point = ft_postion(window, (t_size){-239, 315}, CENTER);
	free(ft_put_image(window, tmenu->map2, (t_size){200, 150}, point));
	point = ft_postion(window, (t_size){639, -25}, CENTER);
	free(ft_put_image(window, tmenu->map3, (t_size){200, 150}, point));
	point = ft_postion(window, (t_size){200, -25}, CENTER);
	free(ft_put_image(window, tmenu->map4, (t_size){200, 150}, point));
	point = ft_postion(window, (t_size){-239, -25}, CENTER);
	free(ft_put_image(window, tmenu->map5, (t_size){200, 150}, point));
}
