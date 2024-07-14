/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:44:22 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 18:16:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	ft_destroy_image(t_window *window, void *img)
{
	mlx_destroy_image(window->mlx, img);
}

t_image	*ft_create_image(t_window *window, stringg path, int width, int height,
		int x, int y)
{
	t_image	*ig;

	ig = (t_image *)malloc(sizeof(t_image) * 1);
	if (ig == NULL)
		return (NULL);
	ig->path = path;
	ig->x = x;
	ig->y = y;
	ig->width = width;
	ig->height = height;
	ig->date = mlx_xpm_file_to_image(window->mlx, ig->path, &ig->width,
			&ig->height);
	if (ig->date == NULL)
	{
		free(ig);
		return (NULL);
	}
	return (ig);
}

void	*ft_put_image(t_window *window, stringg path, int width, int height,
		int x, int y)
{
	void	*ig;

	ig = mlx_xpm_file_to_image(window->mlx, path, &width, &height);
	if (ig == NULL)
		return (NULL);
	mlx_put_image_to_window(window->mlx, window->win, ig, x, y);
	return (ig);
}

t_point	ft_postion(t_window *window, t_size size, enum e_postion postion)
{
	t_point point;

	point.x = 0;
	point.y = 0;
	if (postion == CENTER)
	{
		point.x = (window->width - size.width) / 2;
		point.y = (window->height - size.height) / 2;
	}
	return (point);
}
