/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 08:48:21 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/09 17:05:26 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/unit.h"
#include <stdio.h>

static bool	is_object_in_between(struct s_mrt_intersection *intersection, \
	struct s_mrt_lighting *lighting_data, t_mrt_ray *ray, \
	t_mrt_point3d hit_position)
{
	t_mrt_point3d	light_position;
	bool			is_shadow;

	light_position = lighting_data->light_source.scene->origin;
	if (intersection->time < 0)
		is_shadow = false;
	if (ray_distance(ray, intersection->time) < \
	vec3_length(vec3_subtract(light_position, hit_position)))
	{
		printf("id: %d\n", intersection->object.identifier);
		printf("t: %f\n", intersection->time);
		// printf("hit_point to object: %f\n", ray_distance(ray, intersection->time));
		// printf("hit_point to light: %f\n", vec3_length(vec3_subtract(light_position, hit_position)));
		is_shadow = true;
	}
	else
		is_shadow = false;
	return (is_shadow);
}

bool	mrt_is_shadow(struct s_mrt_lighting *lighting_data, \
	struct s_mrt_renderer_data *renderer, t_mrt_vec3 lightv)
{
	t_mrt_ray					ray;
	t_mrt_point3d				hit_position;
	struct s_mrt_intersection	intersection;

	hit_position = vec3_add(lighting_data->hit_position, \
		vec3_smultiply(lighting_data->normal, EPSILON));
	ray = mrt_ray(hit_position, lightv);
	intersection = mrt_intersect_world(renderer, ray);
	mrt_intersections_reset(&renderer->cache.intersections, \
		&renderer->cache.allocators);
	if (mrt_intersection_is_empty(&intersection))
	{
		printf("YES\n");
		return (false);
	}
	else
	{
		return (is_object_in_between(\
			&intersection, lighting_data, &ray, hit_position));
	}
}