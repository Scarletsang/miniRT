/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:44:50 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 16:22:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"
#include <stdio.h>

/**
 * Assumes that the ray's direction is the vector between the intersection
 * point and the point of origin.
*/
void	mrt_lighting_set_position(struct s_mrt_lighting *lighting_data, \
t_mrt_ray *ray, struct s_mrt_intersection intersection)
{
	lighting_data->eye_vector = vec3_negate(ray->direction);
	lighting_data->hit_position = ray_at(ray, intersection.time);
	lighting_data->normal = mrt_lighting_normal_at(\
		intersection.object, lighting_data->hit_position);
}

void	mrt_lighting_set_material(struct s_mrt_lighting *lighting_data, \
struct s_mrt_material *material, struct s_mrt_light_ambient ambient_light)
{
	lighting_data->ambient_effectiveness = ambient_light.scene->ratio;
	lighting_data->material = *material;
	lighting_data->material.color = vec3_multiply(\
		lighting_data->material.color, \
		ambient_light.scene->color);
}

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
