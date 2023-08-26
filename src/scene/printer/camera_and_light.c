/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_and_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:41:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 18:59:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_objects.h"
#include <stdio.h>

void	mrt_scene_camera_print(struct s_mrt_scene_camera *camera)
{
	printf("camera:\n");
	printf("    origin      : ");
	vec3_print(camera->origin);
	printf("    orientation  : ");
	vec3_print(camera->orientation);
	printf("    fov         : %f\n", camera->fov);
}

void	mrt_scene_light_ambient_print(\
struct s_mrt_scene_light_ambient *light_ambient)
{
	printf("light ambient:\n");
	printf("    ratio      : %f\n", light_ambient->ratio);
	printf("    color      : ");
	vec3_print(light_ambient->color);
}

void	mrt_scene_light_point_print(\
struct s_mrt_scene_light_point *light_point)
{
	printf("light point:\n");
	printf("    origin      : ");
	vec3_print(light_point->origin);
	printf("    ratio       : %f\n", light_point->ratio);
	printf("    color       : ");
	vec3_print(light_point->color);
}
