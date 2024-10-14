/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:04:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/14 13:09:05 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
#define COLOR_H

typedef union u_color
{
	uint32_t	pixel_color;  // 32-bit pixel color
	uint8_t		colors[4];    // Array of 4 bytes (RGBA or ARGB)
} t_color;

#endif
