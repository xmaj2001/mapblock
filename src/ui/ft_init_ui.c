/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:47:16 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 12:30:21 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_init_menu(t_menu *tmenu)
{
	tmenu->background = "./assets/menu/background.xpm";
	tmenu->btn_play = "./assets/menu/btn_play.xpm";
	tmenu->btn_map = "./assets/menu/btn_map.xpm";
	tmenu->btn_exit = "./assets/menu/btn_exit.xpm";
	tmenu->xjose = "./assets/menu/XJOSE.xpm";
	tmenu->title = "./assets/menu/title.xpm";
}

void	ft_init_menu_map(t_menu_map *tmenu)
{
	tmenu->background = "./assets/map/background.xpm";
	tmenu->map0 = "./assets/map/BL0.xpm";
	tmenu->map1 = "./assets/map/BL1.xpm";
	tmenu->map2 = "./assets/map/BL2.xpm";
	tmenu->map3 = "./assets/map/BL3.xpm";
	tmenu->map4 = "./assets/map/BL4.xpm";
	tmenu->map5 = "./assets/map/BL5.xpm";
}
