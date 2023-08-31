/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:13 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 12:24:00 by kisikogl         ###   ########.fr       */
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

struct s_mrt_scene_entry	mrt_default_scene_cylinder(void)
{
	return (mrt_scene_entry((struct s_mrt_scene_cylinder[1]){\
		(struct s_mrt_scene_cylinder){\
			.center = vec3(5.0, 0, 5.0), \
			.orientation = vec3_normalize(vec3(1.0, 1.0, 0.0)), \
			.diameter = 4.0, \
			.height = 10.0, \
			.color = vec3(30.0, 255.0, 30.0)
		} \
	}, ENTRY_CYLINDER));
}

int	mrt_default_scene(struct s_mrt_scene *scene)
{
	if (mrt_scene_add_entry(scene, mrt_default_scene_cylinder(), false))
		return (EXIT_FAILURE);
	return (mrt_scene_add_entry(scene, mrt_default_scene_camera(), true));
}
