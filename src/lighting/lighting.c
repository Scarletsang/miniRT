/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:44:50 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 15:15:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/lighting.h"

/**
 * Assumes that the ray's direction is the vector between the intersection
 * point and the point of origin.
*/
void	mrt_lighting_set_position(struct s_mrt_lighting *lighting_data, \
t_mrt_ray *ray, struct s_mrt_intersection intersection)
{
	lighting_data->eye_vector = vec3_negate(ray->direction);
	lighting_data->hit_position = ray_at(ray, intersection.time);
	lighting_data->normal = mrt_world_normal_at(\
		intersection.object, lighting_data->hit_position);
}

void	mrt_lighting_set_material(struct s_mrt_lighting *lighting_data, \
struct s_mrt_material *material, struct s_mrt_light_ambient ambient_light)
{
	lighting_data->diffuse_effectiveness = ambient_light.scene->ratio;
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
