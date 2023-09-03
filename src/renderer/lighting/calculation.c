/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:06:51 by htsang            #+#    #+#             */
/*   Updated: 2023/09/03 03:28:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"

/**
 * @details reflectv = in - normal * 2 * dot(in, normal)
*/
static t_mrt_vec3	mrt_lights_reflect(t_mrt_vec3 in_light_vector, \
t_mrt_vec3 normal)
{
	return (vec3_subtract(in_light_vector, \
		vec3_smultiply(normal, 2 * vec3_dot(in_light_vector, normal))));
}

void	mrt_lights_calculation_basic(struct s_mrt_lights_calculation *result, \
struct s_mrt_lighting *lighting_data)
{
	result->effective_color = vec3_multiply(lighting_data->material.color, \
		lighting_data->light_source.scene->color);
	result->lightv = vec3_normalize(\
		vec3_subtract(lighting_data->light_source.scene->origin, \
			lighting_data->hit_position));
	result->light_normal_angle = \
		vec3_dot(result->lightv, lighting_data->normal);
}

void	mrt_lights_calculation_reflection(\
struct s_mrt_lights_calculation *result, struct s_mrt_lighting *lighting_data)
{
	result->reflectv = mrt_lights_reflect(vec3_negate(result->lightv), \
		lighting_data->normal);
	result->reflect_eye_angle = vec3_dot(result->reflectv, \
		lighting_data->eye_vector);
}

t_mrt_color	mrt_lighting_calculate(struct s_mrt_lighting *lighting_data)
{
	struct s_mrt_lights_calculation	calculation;
	struct s_mrt_lights				lights;

	mrt_lights_calculation_basic(&calculation, lighting_data);
	mrt_lights_set_ambient(&lights, calculation.effective_color, \
		lighting_data->diffuse_effectiveness);
	if (calculation.light_normal_angle < 0)
		return (lights.ambient);
	mrt_lights_set_diffuse(&lights, &calculation, \
		lighting_data->material.diffuse);
	mrt_lights_calculation_reflection(&calculation, lighting_data);
	if (calculation.reflect_eye_angle <= 0)
		return (mrt_lights_combine_diffuse_level(&lights));
	mrt_lights_set_specular(&lights, &calculation, lighting_data);
	return (mrt_lights_combine_specular_level(&lights));
}
