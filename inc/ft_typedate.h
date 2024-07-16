/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typedate.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xjose <xjose@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:56:52 by xjose             #+#    #+#             */
/*   Updated: 2024/07/16 09:20:57 by xjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPEDATE_H

# define FT_TYPEDATE_H

# define FALSE 0

# define TRUE 1

typedef struct s_size
{
	int	width;
	int	height;
}		t_size;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_postion
{
	int	x;
	int	y;
	int	z;
}		t_postion;

enum	e_postion
{
	NUNE = 0,
	LEFT = 1,
	CENTER = 2,
	RIGTH = 3,
	DOWN = 4
};

enum	e_color
{
	WHITE = 0xFFFFFF,
	BLACK = 0x000000,
	RED = 0xFF0000,
	GREEN = 0x00FF00,
	BLUE = 0x0000FF,
	YELLOW = 0xFFFF00,
	CYAN = 0x00FFFF,
	MAGENTA = 0xFF00FF,
	ORANGE = 0xFFA500,
	PINK = 0xFFC0CB,
	PURPLE = 0x800080,
	BROWN = 0xA52A2A,
	GRAY = 0x808080,
	LIGHT_GRAY = 0xD3D3D3,
	DARK_GRAY = 0xA9A9A9,
	NAVY = 0x000080,
	TEAL = 0x008080,
	OLIVE = 0x808000,
	MAROON = 0x800000,
	LIME = 0xBFFF00,
	INDIGO = 0x4B0082,
	GOLD = 0xFFD700,
	SILVER = 0xC0C0C0,
	BEIGE = 0xF5F5DC,
	LIGHT_BLUE = 0xADD8E6,
	LIGHT_GREEN = 0x90EE90,
	LIGHT_PINK = 0xFFB6C1,
	LIGHT_YELLOW = 0xFFFFE0,
	DARK_BLUE = 0x00008B,
	DARK_RED = 0x8B0000,
	DARK_GREEN = 0x006400,
	DARK_ORANGE = 0xFF8C00,
	DARK_PURPLE = 0x6A0DAD
};

#endif