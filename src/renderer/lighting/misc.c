/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 06:00:03 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 06:00:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"
#include <stdio.h>

void	mrt_lighting_set_light_source(struct s_mrt_lighting *lighting_data, \
struct s_mrt_light_point light_source)
{
	lighting_data->light_source = light_source;
}

void	mrt_lighting_print(struct s_mrt_lighting *lighting_data)
{
	printf("eye_vector           : ");
	vec3_print(lighting_data->eye_vector);
	printf("hit_position         : ");
	vec3_print(lighting_data->hit_position);
	printf("normal               : ");
	vec3_print(lighting_data->normal);
	printf("material             :\n");
	mrt_material_print(&lighting_data->material);
	printf("ambient_effectiveness: %f\n", lighting_data->ambient_effectiveness);
	printf("light_source         : ");
	if (lighting_data->light_source.scene)
		mrt_scene_light_point_print(lighting_data->light_source.scene);
	else
		printf("NULL\n");
}
