/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:47:45 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 04:42:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/camera.h"
#include "MINIRT/scene/s_objects.h"
#include <stdlib.h>

struct s_mrt_camera	*mrt_camera(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length)
{
	struct s_mrt_camera	*camera;

	camera = malloc(sizeof(struct s_mrt_camera));
	if (!camera)
		return (NULL);
	scene_camera->orientation = vec3_normalize(scene_camera->orientation);
	*camera = (struct s_mrt_camera){
		.scene = scene_camera,
		.screen = screen,
		.focal_length = focal_length,
		.viewport = mrt_viewport(scene_camera, screen, focal_length)
	};
	return (camera);
}

void	mrt_camera_refresh(struct s_mrt_camera *camera)
{
	camera->viewport = mrt_viewport(camera->scene, camera->screen, \
		camera->focal_length);
}

void	mrt_camera_free(struct s_mrt_camera *camera)
{
	free(camera->scene);
}
