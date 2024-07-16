/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 17:39:03 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 12:58:26 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	ft_hook(t_window *window, t_event event, int (*funct)(), void *param)
{
	mlx_hook(window->win, event.code, event.mask, funct, param);
}

void	ft_destroy_event(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, (t_event){17, 1L << 0}, funct, param);
}
