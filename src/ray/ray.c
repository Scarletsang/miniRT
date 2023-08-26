/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:37:29 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:24:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/ray.h"
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

t_mrt_color	mrt_ray_color(t_mrt_ray	*ray, struct s_mrt_world *world)
{
	double						t;
	int							ray_hit;

	ray_hit = mrt_ray_is_hit(ray, world);
	if (ray_hit == ENTRY_SPHERE)
		return (vec3(255.0, 30.0, 30.0));
	t = 0.5 * (ray->direction_unit.y + 1.0);
	return (vec3(\
		mrt_lerp(mrt_range(225.0, 145.0), t), \
		mrt_lerp(mrt_range(225.0, 165.0), t), \
		mrt_lerp(mrt_range(255.0, 255.0), t) \
	));
}

t_mrt_point3d	ray_at(t_mrt_ray *ray, double t)
{
	return (vec3_add(ray->origin, vec3_multiply(ray->direction, t)));
}
