/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:05:38 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 05:29:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/camera.h"
#include <math.h>

/**
 * @brief Calculate the lower left corner of the viewport
 * @details equation = origin - horizontal / 2 - vertical / 2 - focal_length
*/
static t_mrt_vec3	mrt_viewport_top_left_corner(\
struct s_mrt_scene_camera *scene_camera, t_mrt_vec3 horizontal, \
t_mrt_vec3 vertical, double focal_length)
{
	t_mrt_vec3	top_left_corner;

	top_left_corner = vec3_subtract(\
		scene_camera->origin, \
		vec3_smultiply(scene_camera->orientation, focal_length));
	top_left_corner = vec3_subtract(\
		top_left_corner, \
		vec3_sdivide(horizontal, 2.0));
	top_left_corner = vec3_subtract(\
		top_left_corner, \
		vec3_sdivide(vertical, 2.0));
	return (top_left_corner);
}

double	mrt_degrees_to_radians(double degree)
{
	return (degree * (M_PI / 180.0));
}

double	mrt_focal_length_height(double fov)
{
	return (2.0 * tan(mrt_degrees_to_radians(fov) / 2.0));
}

struct s_mrt_viewport	mrt_viewport(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length)
{
	t_mrt_direction3d	horizontal;
	t_mrt_direction3d	vertical;
	t_mrt_dimension		dimension;
	t_mrt_vec3			u;
	t_mrt_vec3			v;

	dimension.y = 2.0 * focal_length * \
		mrt_focal_length_height(scene_camera->fov);
	dimension.x = dimension.y * screen.aspect_ratio;
	u = vec3_normalize(vec3_cross(vec3(0, 1, 0), scene_camera->orientation));
	v = vec3_cross(scene_camera->orientation, u);
	horizontal = vec3_smultiply(u, dimension.x);
	vertical = vec3_smultiply(vec3_negate(v), dimension.y);
	return ((struct s_mrt_viewport){
		.dimension = dimension,
		.horizontal = horizontal,
		.vertical = vertical,
		.top_left_corner = mrt_viewport_top_left_corner(
			scene_camera
			, horizontal
			, vertical
			, focal_length),
		.pixel_horizontal = vec3_sdivide(horizontal, screen.width),
		.pixel_vertical = vec3_sdivide(vertical, screen.height)
	});
}
