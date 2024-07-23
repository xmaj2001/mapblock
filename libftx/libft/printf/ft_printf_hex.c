/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:19:30 by xjose             #+#    #+#             */
/*   Updated: 2024/06/18 20:35:14 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_hex(unsigned int n, const char c, int *len)
{
	if (n > 15)
		ft_printf_hex(n / 16, c, len);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
	(*len)++;
}

void	ft_print_hexux(unsigned long long n, int *len)
{
	if (n > 15)
		ft_print_hexux(n / 16, len);
	write(1, &"0123456789abcdef"[n % 16], 1);
	(*len)++;
}

void	ft_print_point(unsigned long long p, int *len)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	ft_putstr("0x");
	(*len)++;
	(*len)++;
	ft_print_hexux(p, len);
}
