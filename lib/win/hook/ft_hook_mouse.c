/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:25:46 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 18:26:53 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	ft_mouse_hook(t_window *window, int (*funct)(), void *param)
{
	mlx_mouse_hook(window->win, funct, param);
}

void	ft_mouse_press(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, MOUSE_PRESS, funct, param);
}

void	ft_mouse_release(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, MOUSE_RELEASE, funct, param);
}
void	ft_mouse_enter(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, MOUSE_ENTER, funct, param);
}

void	ft_mouse_leave(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, MOUSE_LEAVE, funct, param);
}

void	ft_mouse_move(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, MOUSE_MOVE, funct, param);
}
