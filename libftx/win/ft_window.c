/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:01:17 by xjose             #+#    #+#             */
/*   Updated: 2024/07/20 16:17:40 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

void	ft_start_window(t_window *window)
{
	mlx_loop(window->mlx);
}

void	ft_clear_window(t_window *window)
{
	mlx_clear_window(window->mlx, window->win);
	free(window);
}

t_window	*ft_create_window(char *title, int width, int height,
		enum e_color backgorund)
{
	t_window	*window;

	window = (t_window *)malloc(sizeof(t_window) * 1);
	if (window == NULL)
		return (NULL);
	window->mlx = mlx_init();
	if (window->mlx == NULL)
	{
		free(window);
		return (NULL);
	}
	window->title = title;
	window->width = width;
	window->height = height;
	window->background = backgorund;
	window->win = mlx_new_window(window->mlx, window->width, window->height,
			window->title);
	if (window->win == NULL)
	{
		free(window);
		return (NULL);
	}
	ft_set_color(window, window->background);
	return (window);
}
