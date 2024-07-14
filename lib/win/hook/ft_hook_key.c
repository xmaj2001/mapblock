/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:51:28 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 18:26:33 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	ft_key_hook(t_window *window, int (*func)(), void *param)
{
	mlx_key_hook(window->win, func, param);
}

void	ft_keyup(t_window *window, int (*funct)(), void *param)
{
	mlx_key_hook(window->win, funct, param);
}

void	ft_keypress(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, KEY_PRESS_EVENT, funct, param);
}

void	ft_keyrelease(t_window *window, int (*funct)(), void *param)
{
	ft_hook(window, KEY_RELEASE_EVENT, funct, param);
}
