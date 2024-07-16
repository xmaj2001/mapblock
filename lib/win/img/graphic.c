/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:31:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 16:34:20 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	ft_set_color(t_window *window, enum e_color cor)
{
	t_image	ig;
	void	*img_ptr;

	ig.x = 0;
	ig.y = 0;
	img_ptr = mlx_new_image(window->mlx, window->width, window->height);
	if (img_ptr == NULL)
		return ;
	ig.data = (int *)mlx_get_data_addr(img_ptr, &ig.bpp, &ig.size_line,
			&ig.endian);
	while (ig.y++ < window->height)
	{
		ig.x = 0;
		while (ig.x++ < window->width)
			ig.data[ig.y * (ig.size_line / 4) + ig.x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, 0, 0);
}

void	*ft_setdraw(t_window *window, t_size size, t_point p, enum e_color cor)
{
	t_image	ig;
	void	*img_ptr;

	ig.x = 0;
	ig.y = 0;
	img_ptr = mlx_new_image(window->mlx, size.width, size.height);
	if (img_ptr == NULL)
		return (NULL);
	ig.data = (int *)mlx_get_data_addr(img_ptr, &ig.bpp, &ig.size_line,
			&ig.endian);
	while (ig.y++ < size.height)
	{
		ig.x = 0;
		while (ig.x++ < size.width)
			ig.data[ig.y * (ig.size_line / 4) + ig.x] = cor;
	}
	mlx_put_image_to_window(window->mlx, window->win, img_ptr, p.x, p.y);
	return (img_ptr);
}

void	ft_put_text(t_window *win, char *texto, t_point point, enum e_color cor)
{
	mlx_string_put(win->mlx, win->win, point.x, point.y, cor, texto);
}
