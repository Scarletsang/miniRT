/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:09:54 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 10:59:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include <stdint.h>

struct s_mrt_renderer_config	mrt_renderer_config_default(void)
{
	return ((struct s_mrt_renderer_config){
		.anti_aliasing_sample_count = 1,
		.maximum_recursion_depth = 5,
		.maximum_world_distance = 1000000.0,
		.thread_count = 1,
		.ppm_output_file_name = "output.ppm"
	});
}

/**
 * @brief Converts pixel coordinates to world space coordinates
 * @details equation: P(u, v) = bottom_left_corner + u * horizontal +
 * v * vertical + origin
*/
t_mrt_direction3d	mrt_pixel_to_direction_from_camera(\
struct s_mrt_camera *camera, uint32_t x, uint32_t y)
{
	t_mrt_point3d	world_coordinate;

	world_coordinate = vec3_add(\
		camera->viewport.lower_left_corner, \
		vec3_multiply(camera->viewport.pixel_horizontal, (double) x));
	world_coordinate = vec3_add(\
		world_coordinate, \
		vec3_multiply(camera->viewport.pixel_vertical, (double) y));
	world_coordinate = vec3_add(\
		world_coordinate, \
		camera->world->origin);
	return (world_coordinate);
}
