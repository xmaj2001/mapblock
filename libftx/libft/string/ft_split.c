/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:10:25 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 17:20:25 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	p;
	size_t	len;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ft_word_count(s, c) + 1);
	if (result == NULL)
		return (NULL);
	len = 0;
	p = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			result[p++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	result[p] = NULL;
	return (result);
}
