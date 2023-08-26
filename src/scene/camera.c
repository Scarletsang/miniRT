/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:44:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 04:49:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_camera.h"
#include "MINIRT/scene.h"
#include <stdlib.h>

struct s_mrt_scene_entry	mrt_scene_camera(struct s_mrt_scene_camera *camera)
{
	union u_scene_entry_object	object;

	object.camera = malloc(sizeof(struct s_mrt_scene_camera));
	if (!object.camera)
		return ((struct s_mrt_scene_entry){
			.identifier = ENTRY_CAMERA,
			.object = mrt_scene_entry_object_empty()
		});
	*object.camera = *camera;
	return ((struct s_mrt_scene_entry){
		.identifier = ENTRY_CAMERA,
		.object = object
	});
}
