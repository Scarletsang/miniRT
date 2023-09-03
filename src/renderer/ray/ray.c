/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:37:29 by htsang            #+#    #+#             */
/*   Updated: 2023/09/03 03:28:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/ray.h"
#include "MINIRT/unit.h"
#include "MINIRT/world.h"
#include "LIBFT/vector.h"
#include <stdlib.h>

t_mrt_ray	mrt_ray_omit_unit(t_mrt_point3d origin, \
t_mrt_direction3d direction)
{
	return ((t_mrt_ray){
		.origin = origin,
		.direction = direction,
		.direction_unit = mrt_direction3d_unit_empty()
	});
}

t_mrt_ray	mrt_ray(t_mrt_point3d origin, t_mrt_direction3d direction)
{
	return ((t_mrt_ray){
		.origin = origin,
		.direction = direction,
		.direction_unit = vec3_normalize(direction)
	});
}

t_mrt_point3d	ray_at(t_mrt_ray *ray, double t)
{
	return (vec3_add(ray->origin, vec3_smultiply(ray->direction, t)));
}
