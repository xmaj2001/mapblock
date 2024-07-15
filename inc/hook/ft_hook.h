/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:05:09 by xjose             #+#    #+#             */
/*   Updated: 2024/07/15 18:40:27 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HOOK_H

# define FT_HOOK_H
typedef struct s_action
{
	int		key;
	void	(*f)();
}			t_action;

void		ft_action(t_window *window, t_action *action);
void		ft_hook(t_window *window, t_event event, int (*funct)(),
				void *param);

void		ft_keyup(t_window *window, int (*funct)(), void *param);
void		ft_keypress(t_window *window, int (*funct)(), void *param);
void		ft_keyrelease(t_window *window, int (*funct)(), void *param);
void		ft_key_hook(t_window *window, int (*funct)(), void *param);

void		ft_mouse_hook(t_window *window, int (*funct)(), void *param);
void		ft_mouse_press(t_window *window, int (*funct)(), void *param);
void		ft_mouse_release(t_window *window, int (*funct)(), void *param);
void		ft_mouse_enter(t_window *window, int (*funct)(), void *param);
void		ft_mouse_leave(t_window *window, int (*funct)(), void *param);
void		ft_mouse_move(t_window *window, int (*funct)(), void *param);
void		ft_destroy_event(t_window *window, int (*funct)(), void *param);
#endif