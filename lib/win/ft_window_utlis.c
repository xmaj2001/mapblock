/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 18:14:14 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_close_window(t_window *win)
{
	ft_clear_window(win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
}
