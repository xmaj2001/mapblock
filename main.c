/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:06:21 by xjose             #+#    #+#             */
/*   Updated: 2024/07/14 19:17:12 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map		g_map;

int	ft_move_player(int key, void *param)
{
	if (KEY_W == key)
		g_map.map = ft_find_player(&g_map, 2);
	else if (KEY_S == key)
		g_map.map = ft_find_player(&g_map, 4);
	else if (KEY_D == key)
		g_map.map = ft_find_player(&g_map, 1);
	else if (KEY_A == key)
		g_map.map = ft_find_player(&g_map, 3);
	if (KEY_Q == key || KEY_ESC == key)
		ft_close_window(g_map.win);
	ft_get_item_map(&g_map);
	ft_print_terminal(g_map);
	ft_inc_map(g_map, CENTER, false);
}

static void	ft_check_map(int fd)
{
	if (ft_get_map(fd, &g_map) == NULL)
	{
		ft_printf("MAP INVALIDE\n");
		exit(1);
	}
}

static void	ft_init_map(t_window *win)
{
	g_map.win = win;
	g_map.obs.block = "./assets/wall.xpm";
	g_map.obs.exit = "./assets/E0.xpm";
	g_map.obs.empty = "./assets/0.xpm";
	g_map.obs.player = "./assets/P0.xpm";
	g_map.obs.jaba = "./assets/1C.xpm";
	g_map.igh = 40;
	g_map.igw = 40;
	ft_inc_map(g_map, CENTER, true);
}

int	main(int c, char *v[])
{
	t_window	*window;
	t_size		size;

	if (c >= 2)
	{
		ft_check_map(ft_open_map(v[1]));
		size = ft_get_size_map_win(g_map.map, 40);
		window = ft_create_window("SO_LONG", size.width, size.height, BLACK);
		ft_init_map(window);
		ft_keyup(window, ft_move_player, window);
		ft_destroy_event(window, ft_close_window, window);
		ft_start_window(window);
	}
	else
	{
		ft_printf("Argument invalid\n");
		exit(1);
	}
	return (0);
}
