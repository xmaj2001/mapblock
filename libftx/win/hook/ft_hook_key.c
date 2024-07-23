/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:51:28 by xjose             #+#    #+#             */
/*   Updated: 2024/07/20 16:13:51 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftx.h"

void	ft_key_hook(t_window *window, int (*func)(), void *param)
{
	mlx_key_hook(window->win, func, param);
}

void	ft_keyup(t_window *window, int (*funct)(), void *param)
{
	mlx_key_hook(window->win, funct, param);
}
