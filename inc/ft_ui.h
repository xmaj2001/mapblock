/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:32:16 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 11:24:19 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UI_H

# define FT_UI_H

typedef struct s_menu
{
	int		map;
	int		menu;
	char	*title;
	char	*background;
	char	*btn_play;
	char	*btn_map;
	char	*btn_exit;
	char	*xjose;

}			t_menu;

typedef struct s_menu_map
{
	int		map;
	int		menu;
	char	*background;
	char	*map0;
	char	*map1;
	char	*map2;
	char	*map3;
	char	*map4;
	char	*map5;

}			t_menu_map;

int			ft_show_menu(int key, t_window *window, t_menu *menu);
int			ft_show_menu_map(int key, t_window *window, t_menu_map *tmenu);
void		ft_create_menu(t_window *window, t_menu *menu);
void		ft_init_menu(t_menu *menu);
void		ft_init_menu_map(t_menu_map *tmenu);
void		ft_create_ui_map(t_window *window, t_menu_map *tmenu);
t_window	*ft_start_game(t_window *window, int map);
t_window	*ft_start_map_ui(t_window *window);
#endif