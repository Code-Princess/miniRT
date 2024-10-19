/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:04:01 by llacsivy          #+#    #+#             */
/*   Updated: 2024/10/19 15:01:24 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef enum e_colors
{
	OPAC,
	BLUE,
	GREEN,
	RED
}	t_colors;

typedef union u_color
{
	uint32_t	pixel_color;
	uint8_t		colors[4];
}	t_color;

t_color	set_color(int r, int g, int b, int opac);

#endif
