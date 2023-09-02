/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:05:38 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 14:57:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/camera.h"

/**
 * @brief Calculate the lower left corner of the viewport
 * @details equation = origin - horizontal / 2 - vertical / 2 - focal_length
*/
static t_mrt_vec3	mrt_viewport_top_left_corner(\
t_mrt_point3d origin, t_mrt_vec3 horizontal, t_mrt_vec3 vertical, \
double focal_length)
{
	t_mrt_vec3	top_left_corner;

	top_left_corner = vec3_subtract(\
		origin, \
		vec3(0.0, 0.0, focal_length));
	top_left_corner = vec3_subtract(\
		top_left_corner, \
		vec3_sdivide(horizontal, 2.0));
	top_left_corner = vec3_subtract(\
		top_left_corner, \
		vec3_sdivide(vertical, 2.0));
	return (top_left_corner);
}

struct s_mrt_viewport	mrt_viewport(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length)
{
	t_mrt_direction3d	horizontal;
	t_mrt_direction3d	vertical;
	t_mrt_dimension		dimension;

	dimension.y = 2.0;
	dimension.x = dimension.y * screen.aspect_ratio;
	horizontal = vec3(dimension.x, 0.0, 0.0);
	vertical = vec3(0.0, -dimension.y, 0.0);
	return ((struct s_mrt_viewport){
		.dimension = dimension,
		.horizontal = horizontal,
		.vertical = vertical,
		.top_left_corner = mrt_viewport_top_left_corner(
			scene_camera->origin
			, horizontal
			, vertical
			, focal_length),
		.pixel_horizontal = vec3_sdivide(horizontal, screen.width),
		.pixel_vertical = vec3_sdivide(vertical, screen.height)
	});
}
