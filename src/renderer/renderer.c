/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:09:54 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:07:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include <stdint.h>

/**
 * @brief Converts pixel coordinates to world space coordinates
 * @details equation: P(u, v) = top_left_corner + u * horizontal +
 * v * vertical - origin
*/
t_mrt_direction3d	mrt_pixel_to_direction_from_camera(\
struct s_mrt_camera *camera, uint32_t x, uint32_t y)
{
	t_mrt_point3d	world_coordinate;

	world_coordinate = vec3_add(\
		camera->viewport.top_left_corner, \
		vec3_multiply(camera->viewport.pixel_horizontal, (double) x));
	world_coordinate = vec3_add(\
		world_coordinate, \
		vec3_multiply(camera->viewport.pixel_vertical, (double) y));
	world_coordinate = vec3_subtract(\
		world_coordinate, \
		camera->scene->origin);
	return (world_coordinate);
}
