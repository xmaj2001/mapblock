/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:00:21 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:28:27 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map		g_map;

static void	ft_check_map(int fd)
{
	if (ft_get_map(fd, &g_map) == NULL)
	{
		ft_printf("MAP INVALIDE\n");
		exit(1);
	}
}

void	ft_end_game(int end)
{
	if(end == 0)
	{
		g_map.paths.player = "./assets/I.xpm";
		ft_print_map(g_map, CENTER, FALSE);
		g_map.paths.block = "./assets/I.xpm";
		g_map.paths.empty = "./assets/I.xpm";
		g_map.paths.jaba = "./assets/I.xpm";
		g_map.paths.exit = "./assets/I.xpm";
		ft_print_map(g_map, CENTER, TRUE);
		ft_close_window(g_map.win);
	}
	else
	{
		g_map.paths.player = "./assets/player/PF.xpm";
		ft_print_map(g_map, CENTER, FALSE);
		g_map.paths.block = "./assets/F.xpm";
		g_map.paths.empty = "./assets/F.xpm";
		g_map.paths.jaba = "./assets/F.xpm";
		g_map.paths.exit = "./assets/F.xpm";
		ft_print_map(g_map, CENTER, TRUE);
		ft_close_window(g_map.win);
	}
}

static int	ft_load_map(void)
{
	ft_set_item_map(&g_map);
	ft_print_map(g_map, CENTER, FALSE);
	if (g_map.items.jaba == 0)
		g_map.paths.exit = "./assets/EO.xpm";
	if (g_map.items.exit == 0 && g_map.items.jaba == 0)
		ft_end_game(1);
	else if (g_map.items.player == 0 || g_map.cubou == 1)
		ft_end_game(0);
	ft_print_map(g_map, CENTER, FALSE);
	return (0);
}

static int	ft_move_player(int key, void *param)
{
	(void)param;
	if (KEY_W == key)
		ft_player_move(&g_map, 2, "./assets/player/PW.xpm");
	else if (KEY_S == key)
		ft_player_move(&g_map, 4, "./assets/player/PS.xpm");
	else if (KEY_D == key)
		ft_player_move(&g_map, 1, "./assets/player/PD.xpm");
	else if (KEY_A == key)
		ft_player_move(&g_map, 3, "./assets/player/PA.xpm");
	if (KEY_Q == key || KEY_ESC == key)
		ft_close_window(g_map.win);
	ft_enemy_move(&g_map);
	ft_print_terminal(g_map);
	return (1);
}

t_window	*ft_start_game(t_window *window, int map)
{
	t_size	size;

	ft_set_maps(&g_map);
	ft_check_map(ft_open_map(g_map.maps[map]));
	size = ft_get_size_map_win(g_map.matrix, 40);
	ft_clear_window(window);
	mlx_destroy_display(window->mlx);
	window = ft_create_window("SO LONG", size.width, size.height, TT);
	ft_init_map(window, &g_map);
	ft_print_map(g_map, CENTER, TRUE);
	ft_keyup(window, ft_move_player, window);
	ft_destroy_event(window, ft_close_window, window);
	mlx_loop_hook(window->mlx, ft_load_map, NULL);
	ft_start_window(window);
	return (window);
}
