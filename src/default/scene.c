/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:13 by htsang            #+#    #+#             */
/*   Updated: 2023/08/15 13:12:05 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/scene/s_game_object.h"

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
	if (mrt_scene_add_entry(scene, mrt_scene_sphere(\
	vec3(5.0, 0.0, 10.0), 5.0, vec3(255.0, 30.0, 30.0))))
		return (EXIT_FAILURE);
	return (mrt_scene_add_entry(scene, mrt_default_scene_camera()));
}
