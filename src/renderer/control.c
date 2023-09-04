/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:09:54 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 20:54:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/renderer/lighting.h"
#include <stdint.h>

t_mrt_color	mrt_render_lighting(struct s_mrt_renderer_data *renderer, \
	struct s_mrt_lighting *lighting_data)
{
	t_ft_vector_iterator	iterator;
	t_mrt_color				color;

	ft_vector_iterator_begin(&iterator, &renderer->world->point_lights);
	color = vec3(0, 0, 0);
	while (!iterator.is_end)
	{
		mrt_lighting_set_light_source(lighting_data, \
			*((struct s_mrt_world_entry *) \
			ft_vector_iterator_current(&iterator))->object.light_point);
		color = vec3_add(color, mrt_lighting_calculate(lighting_data));
		ft_vector_iterator_next(&iterator);
	}
	return (color);
}

t_mrt_color	mrt_render(struct s_mrt_renderer_data *renderer, \
t_mrt_ray ray, struct s_mrt_intersection intersection)
{
	struct s_mrt_lighting		lighting_data;

	mrt_lighting_set_position(&lighting_data, &ray, intersection);
	mrt_lighting_set_material(&lighting_data, \
		mrt_world_entry_get_material(intersection.object), \
		*mrt_world_get_ambient_light(renderer->world));
	lighting_data.light_source.scene = NULL;
	// return (mrt_render_lighting(renderer, &lighting_data));
	return (mrt_vec3_unit_color(lighting_data.normal));
}

/**
 * @brief Converts pixel coordinates to world space coordinates
 * @details equation: P(u, v) = top_left_corner + u * horizontal +
 * v * vertical - origin
*/
t_mrt_ray	mrt_render_ray_generate(struct s_mrt_camera *camera, \
uint32_t x, uint32_t y)
{
	t_mrt_point3d	world_coordinate;

	world_coordinate = vec3_add(\
		camera->viewport.top_left_corner, \
		vec3_smultiply(camera->viewport.pixel_horizontal, (double) x));
	world_coordinate = vec3_add(\
		world_coordinate, \
		vec3_smultiply(camera->viewport.pixel_vertical, (double) y));
	world_coordinate = vec3_subtract(\
		world_coordinate, \
		camera->scene->origin);
	return (mrt_ray(camera->scene->origin, world_coordinate));
}

t_mrt_color	mrt_render_color_at(struct s_mrt_renderer_data *renderer, \
uint32_t x, uint32_t y)
{
	t_mrt_ray					ray;
	struct s_mrt_intersection	intersection;
	t_mrt_color					color;

	ray = mrt_render_ray_generate(mrt_world_get_camera(renderer->world), x, y);
	intersection = mrt_intersect_world(renderer, ray);
	if (mrt_intersection_is_empty(&intersection))
		color = vec3(2, 0, 0);
	else
		color = mrt_render(renderer, ray, intersection);
	mrt_intersections_reset(&renderer->cache.intersections, \
		&renderer->cache.allocators);
	return (color);
}