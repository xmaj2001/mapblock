/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:31:40 by xjose             #+#    #+#             */
/*   Updated: 2024/06/18 19:49:49 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	if (nmemb != '\0' && size > 4294967295 / nmemb)
		return (0);
	dst = (void *)malloc(nmemb * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size * nmemb);
	return (dst);
}
