/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:28:57 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 15:08:17 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H

# define FT_MAP_H

typedef struct s_path_imgs
{
	char		*exit;
	char		*jaba;
	char		*block;
	char		*empty;
	char		*player;
	char		*ghost;
}				t_path_imgs;

typedef struct s_items
{
	t_size		size;
	int			player;
	int			block;
	int			jaba;
	int			empty;
	int			ghost;
	int			exit;
}				t_items;

typedef struct s_map
{
	t_window	*win;
	t_items		items;
	t_path_imgs	paths;
	char		**matrix;
	char		*maps[6];
	int			steps;
	int			cubou;
	int			igw;
	int			igh;
	int			move;
}				t_map;

int				ft_open_map(char *path);
int				ft_check_width(char **map);
int				ft_is_rectangle(t_size size);
int				ft_items_required(char **map);
int				ft_count_item(char **map, char item);
int				ft_number_items_is_validate(t_items item);
int				ft_validate_map(char **map, t_items items);

char			*ft_read_file_map(int fd);

void			ft_set_maps(t_map *g_map);
void			ft_init_map(t_window *win, t_map *g_map);
void			ft_set_item_map(t_map *map);
void			ft_print_line(char *line, t_map m, t_point p, int animation);
void			ft_print_map(t_map map, enum e_postion postion, int animation);
void			ft_print_terminal(t_map mp);

t_point			ft_find_char(char **map, char ch);
t_size			ft_get_size_map(char **map);
t_size			ft_get_size_map_win(char **map, int size_img);
t_map			*ft_get_map(int fd, t_map *tmap);
#endif