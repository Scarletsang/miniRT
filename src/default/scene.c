/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:13 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 14:40:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/scene/s_camera.h"

struct s_mrt_scene_entry	mrt_default_scene_camera(void)
{
	return (mrt_scene_camera((struct s_mrt_scene_camera[1]){\
		(struct s_mrt_scene_camera){\
			.origin = (t_mrt_point3d){0, 0, 0}, \
			.orientation = (t_mrt_direction3d_unit){0, 0, 0}, \
			.fov = 0 \
		} \
	}));
}

int	mrt_default_scene(struct s_mrt_scene *scene)
{
	return (mrt_scene_add_entry(scene, mrt_default_scene_camera(), true));
}
