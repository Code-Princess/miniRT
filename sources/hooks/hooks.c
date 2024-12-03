/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:41:04 by llacsivy          #+#    #+#             */
/*   Updated: 2024/12/03 13:55:41 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void esc_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
	}
}

void	resize_hook(void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if ((uint32_t)data->mlx->width != data->image->width || \
		(uint32_t)data->mlx->height != data->image->height)
	{
		mlx_resize_image(data->image, data->mlx->width, \
						data->mlx->height);
	}
}