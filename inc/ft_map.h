/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:28:57 by xjose             #+#    #+#             */
/*   Updated: 2024/07/15 18:38:38 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H

# define FT_MAP_H
typedef struct s_objects
{
	stringg		exit;
	stringg		jaba;
	stringg		block;
	stringg		empty;
	stringg		player;
}				t_objects;

typedef struct s_items
{
	t_size		size;
	int			player;
	int			block;
	int			jaba;
	int			empty;
	int			exit;
}				t_items;

typedef struct s_map
{
	char		**map;
	t_window	*win;
	t_items		items;
	t_objects	obs;
	int			steps;
	int			igw;
	int			igh;
}				t_map;

int				ft_count_item(char **map, char item);
char			*ft_read_map(int fd);
void			ft_get_item_map(t_map *map);
void			ft_print_map(stringg line, t_map map, t_point p,
					bool animation);
void			ft_print_simple_map(stringg line, t_map map, t_point p, bool a);
void			ft_inc_map(t_map map, enum e_postion postion, bool animation);
void			ft_simple_map(t_map map, enum e_postion postion, bool a);
void			ft_print_terminal(t_map mp);
int				ft_open_map(stringg path);

bool			ft_is_valide_items(t_items item);
bool			ft_is_valide_char(char ch);
bool			ft_is_rectangle(t_size size);
bool			ft_is_valide_width(char **map);
bool			ft_validate_map(char **map, t_items items);
bool			ft_items_required(char **map);

t_map			*ft_get_map(int fd, t_map *map);
t_size			ft_get_size_map_win(char **map, int size_img);
t_size			ft_get_size_map(char **map);

#endif