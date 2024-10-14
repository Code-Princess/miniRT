/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linda <linda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:04:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 16:35:16 by linda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef union u_color
{
	uint32_t	pixel_color;  // 32-bit pixel color
	uint8_t		colors[4];    // Array of 4 bytes (RGBA or ARGB)
} t_color;

#endif
