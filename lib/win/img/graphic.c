/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:31:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 18:23:59 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	ft_set_color(t_window *window, enum e_color cor)
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;

	x = 0, y = 0;
	img_ptr = mlx_new_image(window->mlx, window->width, window->height);
	if (img_ptr == NULL)
		return ;
	data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (y++ < window->height)
	{
		x = 0;
		while (x++ < window->width)
			data[y * (size_line / 4) + x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, 0, 0);
}

void	*ft_setdraw(t_window *window, t_size size, int px, int py,
		enum e_color cor)
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		x;
	int		y;

	x = 0, y = 0;
	img_ptr = mlx_new_image(window->mlx, size.width, size.height);
	if (img_ptr == NULL)
		return (NULL);
	data = (int *)mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	while (y++ < size.height)
	{
		x = 0;
		while (x++ < size.width)
			data[y * (size_line / 4) + x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, px, py);
	return (img_ptr);
}

void	ft_put_text(t_window *win, stringg texto, t_point point,
		enum e_color cor)
{
	mlx_string_put(win->mlx, win->win, point.x, point.y, cor, texto);
}
