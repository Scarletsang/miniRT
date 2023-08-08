/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:47:45 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 10:53:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/camera.h"
#include <stdlib.h>

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
		.viewport = mrt_viewport(scene_camera, screen, focal_length)
	};
	return (camera);
}

void	mrt_camera_refresh(struct s_mrt_camera *camera)
{
	camera->viewport = mrt_viewport(camera->world, camera->screen, \
		camera->focal_length);
}

struct s_mrt_camera	*mrt_camera_default(void)
{
	return (mrt_camera(\
		mrt_scene_camera_default().object.camera, \
		mrt_image_default(), \
		1.0 \
	));
}

void	mrt_camera_free(struct s_mrt_camera *camera)
{
	free(camera->world);
}
