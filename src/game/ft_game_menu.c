/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:50:50 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:35:02 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_menu		g_menu;
t_menu_map	g_menu_map;

static int	ft_menu(int key, t_window *window)
{
	ft_show_menu(key, window, &g_menu);
	return (0);
}

static int	ft_menu_map(int key, t_window *window)
{
	ft_show_menu_map(key, window, &g_menu_map);
	return (0);
}

void	ft_start_menu(void)
{
	t_window	*window;

	window = ft_create_window("SO_LONG", 1000, 670, TT);
	g_menu.menu = 0;
	ft_init_menu(&g_menu);
	ft_create_menu(window, &g_menu);
	ft_key_hook(window, ft_menu, window);
	ft_destroy_event(window, ft_close_window, window);
	ft_start_window(window);
}

t_window	*ft_start_map_ui(t_window *window)
{
	ft_clear_window(window);
	mlx_destroy_display(window->mlx);
	window = ft_create_window("SO LONG MAPS", 1000, 670, TT);
	ft_init_menu_map(&g_menu_map);
	g_menu_map.map0 = "./assets/map/BL0A.xpm";
	ft_create_ui_map(window, &g_menu_map);
	g_menu_map.menu = 1;
	ft_key_hook(window, ft_menu_map, window);
	ft_destroy_event(window, ft_close_window, window);
	ft_start_window(window);
	return (window);
}
