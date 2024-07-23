/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:12:36 by xjose             #+#    #+#             */
/*   Updated: 2024/06/18 19:49:32 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	i = -1;
	if (dest == src || !n)
		return (dest);
	if (dest < src)
	{
		while (++i < n)
			d[i] = s[i];
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}
