/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacsivy <llacsivy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:55:22 by llacsivy          #+#    #+#             */
/*   Updated: 2024/11/07 14:56:36 by llacsivy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

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
	static const t_get_normal_ft_array	normal_vec_func[OBJECT_COUNT] = {\
		[PLANE] = &calc_plane_normal_vec, \
		[SPHERE] = &calc_sphere_normal_vec, \
		[CYLINDER] = &calc_cylinder_normal_vec,
	};

	return ((t_get_normal_ft_array *)(normal_vec_func));
}
