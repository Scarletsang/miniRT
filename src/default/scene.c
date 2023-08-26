/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:13 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:15:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/scene/s_objects.h"

struct s_mrt_scene_entry	mrt_default_scene_camera(void)
{
	return (mrt_scene_entry((struct s_mrt_scene_camera[1]){\
		(struct s_mrt_scene_camera){\
			.origin = vec3(0, 0, 0), \
			.orientation = vec3(0, 0, 0), \
			.fov = 0 \
		} \
	}, ENTRY_CAMERA));
}

struct s_mrt_scene_entry	mrt_default_scene_sphere(void)
{
	return (mrt_scene_entry((struct s_mrt_scene_sphere[1]){\
		(struct s_mrt_scene_sphere){\
			.center = vec3(5.0, 0, 10.0), \
			.diameter = 5.0, \
			.color = vec3(255.0, 30.0, 30.0)
		} \
	}, ENTRY_SPHERE));
}

int	mrt_default_scene(struct s_mrt_scene *scene)
{
	if (mrt_scene_add_entry(scene, mrt_default_scene_sphere(), false))
		return (EXIT_FAILURE);
	return (mrt_scene_add_entry(scene, mrt_default_scene_camera(), true));
}
