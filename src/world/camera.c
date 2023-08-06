/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:47:45 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:58:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/camera.h"
#include <stdlib.h>

t_mrt_vec3	mrt_camera_lower_left_corner_calculate(struct s_mrt_camera *camera)
{
	return (vec3_subtract(
				vec3_subtract(
					vec3_subtract(
						camera->world->origin
						, vec3_divide(camera->viewport.horizontal, 2.0))
					, vec3_divide(camera->viewport.vertical, 2.0))
				, vec3(0.0, 0.0, camera->focal_length)));
}

struct s_mrt_camera	*mrt_camera(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length)
{
	struct s_mrt_camera	*camera;

	camera = malloc(sizeof(struct s_mrt_camera));
	if (!camera)
		return (NULL);
	*camera = (struct s_mrt_camera){
		.world = scene_camera,
		.screen = screen,
		.focal_length = focal_length,
		.viewport = (struct s_mrt_viewport){
			.dimension = (t_mrt_dimension){
				.x = screen.width,
				.y = screen.height
			},
			.horizontal = vec3(screen.width, 0.0, 0.0),
			.vertical = vec3(0.0, screen.height, 0.0),
			.lower_left_corner = (t_mrt_vec3) {},
		}
	};
	camera->viewport.lower_left_corner = \
		mrt_camera_lower_left_corner_calculate(camera);
	return (camera);
}

struct s_mrt_camera	*mrt_camera_default(void)
{
	return (mrt_camera(
		mrt_scene_camera_default(),
		mrt_image_default(),
		1.0));
}

void	mrt_camera_free(struct s_mrt_camera *camera)
{
	free(camera->world);
}
