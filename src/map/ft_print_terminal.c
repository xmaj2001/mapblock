/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_terminal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:01:58 by xjose             #+#    #+#             */
/*   Updated: 2024/07/18 14:31:47 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	ft_bar(t_map mp, int cls)
{
	int	x;

	x = -1;
	if (cls)
		ft_clear();
	ft_printf("####");
	while (mp.matrix[0][++x])
		ft_printf("#");
	ft_printf("\n");
}

static void	ft_print_map_t(t_map mp)
{
	t_point	p;

	p.x = 0;
	p.y = -1;
	while (mp.matrix[p.x] != NULL)
	{
		p.y = -1;
		ft_printf("# ");
		while (mp.matrix[p.x][++p.y])
		{
			if (mp.matrix[p.x][p.y] == '1')
				ft_printf("1");
			else if (mp.matrix[p.x][p.y] == '0')
				ft_printf("\033[0;30m0\033[0m");
			else if (mp.matrix[p.x][p.y] == 'C')
				ft_printf("\033[0;33mC\033[0m");
			else if (mp.matrix[p.x][p.y] == 'P')
				ft_printf("\033[0;31mP\033[0m");
			else if (mp.matrix[p.x][p.y] == 'E')
				ft_printf("\033[0;32mE\033[0m");
			else if (mp.matrix[p.x][p.y] == 'V')
				ft_printf("\033[0;31mV\033[0m");
		}
		ft_printf(" #");
		ft_printf("\n");
		p.x++;
	}
}

static void	ft_dategame(t_map mp)
{
	free(ft_setdraw(mp.win, (t_size){mp.win->width, 20}, (t_point){10, 1},
			TT));
	ft_put_text(mp.win, "C: ", (t_point){20, 20}, WHITE);
	ft_put_text(mp.win, ft_itoa(mp.items.jaba), (t_point){55, 20}, LIME);
	ft_put_text(mp.win, "steps: ", (t_point){mp.win->width - 100, 20}, WHITE);
	ft_put_text(mp.win, ft_itoa(mp.steps), (t_point){mp.win->width - 55, 20},
		LIME);
	ft_bar(mp, FALSE);
	ft_printf("steps: %d\n", mp.steps);
	ft_printf("jaba: %d\n", mp.items.jaba);
}

void	ft_print_terminal(t_map mp)
{
	ft_bar(mp, TRUE);
	ft_print_map_t(mp);
	ft_dategame(mp);
}
