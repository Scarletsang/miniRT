/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:13 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 12:44:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"

struct s_mrt_scene_entry	mrt_default_scene_camera(void)
{
	return (mrt_scene_camera(\
		vec3(0.0, 0.0, 0.0), \
		vec3(0.0, 0.0, 1.0), \
		-1.0 \
	));
}

int	mrt_default_scene(struct s_mrt_scene *scene)
{
	return (mrt_scene_add_entry(scene, mrt_default_scene_camera()));
}
