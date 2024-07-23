/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:26:45 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:36:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_show_menu(int key, t_window *window, t_menu *tmenu)
{
	ft_init_menu(tmenu);
	if (KEY_Q == key || KEY_ESC == key)
		ft_close_window(window);
	if (KEY_S == key && tmenu->menu < 2)
		tmenu->menu++;
	else if (KEY_W == key && tmenu->menu > 1)
		tmenu->menu--;
	else if (KEY_ENTER == key)
	{
		if (tmenu->menu == 1)
			ft_start_map_ui(window);
		else if (tmenu->menu == 2)
			ft_close_window(window);
	}
	if (tmenu->menu == 1)
		tmenu->btn_play = "./assets/menu/pc.xpm";
	else if (tmenu->menu == 2)
		tmenu->btn_exit = "./assets/menu/e_active.xpm";
	ft_create_menu(window, tmenu);
	return (0);
}

static void	ft_extra(int key, t_window *window, t_menu_map *tmenu)
{
	if (KEY_Q == key || KEY_ESC == key)
		ft_close_window(window);
	if (KEY_S == key && tmenu->menu < 4)
		tmenu->menu += 3;
	else if (KEY_A == key && tmenu->menu > 1)
		tmenu->menu--;
	if (KEY_D == key && tmenu->menu < 6)
		tmenu->menu++;
	else if (KEY_W == key && tmenu->menu > 3)
		tmenu->menu -= 3;
}

int	ft_show_menu_map(int key, t_window *window, t_menu_map *tmenu)
{
	ft_init_menu_map(tmenu);
	ft_extra(key, window, tmenu);
	if (tmenu->menu == 1)
		tmenu->map0 = "./assets/map/BL0A.xpm";
	else if (tmenu->menu == 2)
		tmenu->map1 = "./assets/map/BL1A.xpm";
	else if (tmenu->menu == 3)
		tmenu->map2 = "./assets/map/BL2A.xpm";
	else if (tmenu->menu == 4)
		tmenu->map3 = "./assets/map/BL3A.xpm";
	else if (tmenu->menu == 5)
		tmenu->map4 = "./assets/map/BL4A.xpm";
	else if (tmenu->menu == 6)
		tmenu->map5 = "./assets/map/BL5A.xpm";
	if (KEY_ENTER == key && tmenu->menu > 0)
		ft_start_game(window, tmenu->menu - 1);
	ft_create_ui_map(window, tmenu);
	return (0);
}
