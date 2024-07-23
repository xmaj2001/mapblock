/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:28:41 by xjose             #+#    #+#             */
/*   Updated: 2024/07/07 07:53:06 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char *argv[])
{
	char	**result;

	result = ft_split(argv[1], '\n');
	while (*result)
	{
		printf("%s42\n", *result);
		result++;
	}
	return (0);
}
