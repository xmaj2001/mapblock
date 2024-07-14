/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:01:58 by xjose             #+#    #+#             */
/*   Updated: 2024/07/13 20:56:58 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_bar(t_map mp, bool cls)
{
	int	x;

	x = -1;
	if(cls)
		ft_clear();
	ft_printf("####");
	while (mp.map[0][++x])
		ft_printf("#");
	ft_printf("\n");
}

static void	ft_print_map_t(t_map mp)
{
	t_point	p;

	p.x = -1;
	p.y = 0;
	while (mp.map[p.y] != NULL)
	{
		p.x = -1;
		ft_printf("# ");
		while (mp.map[p.y][++p.x])
		{
			if (mp.map[p.y][p.x] == '1')
				ft_printf("1");
			else if (mp.map[p.y][p.x] == '0')
				ft_printf("\033[0;30m0\033[0m");
			else if (mp.map[p.y][p.x] == 'C')
				ft_printf("\033[0;33mC\033[0m");
			else if (mp.map[p.y][p.x] == 'P')
				ft_printf("\033[0;31mP\033[0m");
			else if (mp.map[p.y][p.x] == 'E')
				ft_printf("\033[0;32mE\033[0m");
		}
		ft_printf(" #");
		ft_printf("\n");
		p.y++;
	}
}

static void	ft_dategame(t_map mp)
{
	free(ft_setdraw(mp.win, (t_size){mp.win->width, 20}, 10, 1, BLACK));
	ft_put_text(mp.win, "JABA: ", (t_point){20, 20}, WHITE);
	ft_put_text(mp.win, ft_itoa(mp.items.jaba), (t_point){55, 20}, LIME);
	ft_put_text(mp.win, "steps: ", (t_point){mp.win->width - 100, 20}, WHITE);
	ft_put_text(mp.win, ft_itoa(mp.steps), (t_point){mp.win->width - 55, 20},
		LIME);
	ft_bar(mp, false);
	ft_printf("steps: %d\n", mp.steps);
	ft_printf("jaba: %d\n", mp.items.jaba);
}

void	ft_print_terminal(t_map mp)
{
	ft_bar(mp, true);
	ft_print_map_t(mp);
	ft_dategame(mp);
}
