/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:05:09 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 17:22:34 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_event
{
	int				code;
	int				mask;
}					t_event;

# define KEY_PRESS_EVENT (t_event) { 2, 1L << 0 }

# define DESTROY (t_event) { 17, 1L << 0 }

# define KEY_RELEASE_EVENT (t_event) { 3, 1L << 1 }

# define MOUSE_PRESS (t_event) { 4, 1L << 2 }

# define MOUSE_RELEASE (t_event) { 5, 1L << 3 }

# define MOUSE_MOVE (t_event) { 6, 1L << 6 }

# define MOUSE_ENTER (t_event) { 7, 1L << 4 }

# define MOUSE_LEAVE (t_event) { 8, 1L << 5 }
