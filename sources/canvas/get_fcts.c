/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:55:22 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/13 19:47:56 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"
#include "../../includes/parser.h"

t_hit_pt_ft_array	*get_hit_pt_ft(void)
{
	static const t_hit_pt_ft_array	hit_pt_func_array[OBJECT_COUNT] = {\
		[PLANE] = &find_plane_hitpt, \
		[SPHERE] = &find_sphere_hitpt, \
		[CYLINDER] = &find_cylinder_hitpt,
	};

	return ((t_hit_pt_ft_array *)(hit_pt_func_array));
}

t_get_normal_ft_array	*get_normal_vec_ft(void)
{
	static const t_get_normal_ft_array	normal_vec_func_array[OBJECT_COUNT] = {\
		[PLANE] = &calc_plane_normal_vec, \
		[SPHERE] = &calc_sphere_normal_vec, \
		[CYLINDER] = &calc_cylinder_normal_vec,
	};

	return ((t_get_normal_ft_array *)(normal_vec_func_array));
}

t_get_parse_ft_array	*get_parse_ft(void)
{
	static const t_get_parse_ft_array	get_parse_ft_array[OBJECT_COUNT] = {\
		[AMB_LIGHT] = &parse_amb_light_input, \
		[CAMERA] = &parse_camera_input, \
		[LIGHT] = &parse_light_input, \
		[PLANE] = &parse_plane_input, \
		[SPHERE] = &parse_sphere_input, \
		[CYLINDER] = &parse_cylinder_input,
	};

	return ((t_get_parse_ft_array *)(get_parse_ft_array));
}
