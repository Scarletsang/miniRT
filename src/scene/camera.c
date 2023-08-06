/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:44:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:52:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_camera.h"
#include <stdlib.h>

struct s_mrt_scene_camera	*mrt_scene_camera(t_mrt_point3d origin, \
t_mrt_direction3d_unit orientation, t_mrt_degrees fov)
{
	struct s_mrt_scene_camera	*camera;

	camera = malloc(sizeof(struct s_mrt_scene_camera));
	if (!camera)
		return (NULL);
	*camera = (struct s_mrt_scene_camera){
		.origin = origin,
		.orientation = orientation,
		.fov = fov};
	return (camera);
}

struct s_mrt_scene_camera	*mrt_scene_camera_default(void)
{
	return (mrt_scene_camera(
		vec3(0.0, 0.0, 0.0),
		vec3(0.0, 0.0, 1.0),
		-1.0));
}
