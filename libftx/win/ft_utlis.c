/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:10 by xjose             #+#    #+#             */
/*   Updated: 2024/07/21 05:12:45 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftx.h"

int	ft_close_window(t_window *win)
{
	ft_clear_window(win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
}
