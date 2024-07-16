/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:58:52 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 09:22:52 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WINDOW_H

# define FT_WINDOW_H

typedef struct s_window
{
	char			*title;
	int				width;
	int				height;
	enum e_color	background;
	void			*mlx;
	void			*win;
}					t_window;

void				ft_set_color(t_window *window, enum e_color cor);
void				ft_start_window(t_window *window);
void				ft_clear_window(t_window *window);
t_window			*ft_create_window(char *title, int width, int height,
						enum e_color backgorund);
int					ft_close_window(t_window *win);

#endif