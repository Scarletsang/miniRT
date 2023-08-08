/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:44:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 10:52:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_camera.h"
#include <stdlib.h>

struct s_mrt_scene_entry	mrt_scene_camera(t_mrt_point3d origin, \
t_mrt_direction3d_unit orientation, t_mrt_degrees fov)
{
	union u_scene_entry_object	object;

	object.camera = malloc(sizeof(struct s_mrt_scene_camera));
	if (!object.camera)
		return ((struct s_mrt_scene_entry){
			.identifier = ENTRY_CAMERA,
			.object = mrt_scene_entry_object_empty()
		});
	*object.camera = (struct s_mrt_scene_camera){
		.origin = origin,
		.orientation = orientation,
		.fov = fov};
	return ((struct s_mrt_scene_entry){
		.identifier = ENTRY_CAMERA,
		.object = object
	});
}

struct s_mrt_scene_entry	mrt_scene_camera_default(void)
{
	return (mrt_scene_camera(\
		vec3(0.0, 0.0, 0.0), \
		vec3(0.0, 0.0, 1.0), \
		-1.0 \
	));
}
