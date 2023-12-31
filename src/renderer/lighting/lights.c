/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:07:45 by htsang            #+#    #+#             */
/*   Updated: 2023/09/10 12:51:03 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"
#include "MINIRT/unit.h"
#include <math.h>
#include <stdio.h>

void	mrt_lights_add_ambient(t_mrt_percentage *light, \
t_mrt_color material_color, double ambient_effectiveness)
{
	*light = vec3_add(*light, vec3_smultiply(material_color, \
	ambient_effectiveness));
}

void	mrt_lights_add_diffuse(t_mrt_percentage *light, \
struct s_mrt_lights_calculation *calculation, double diffuse_effectiveness)
{
	*light = vec3_add(*light, vec3_smultiply(calculation->effective_color, \
		diffuse_effectiveness * calculation->light_normal_angle));
}

void	mrt_lights_add_specular(t_mrt_percentage *light, \
struct s_mrt_lights_calculation *calculation, \
struct s_mrt_lighting *lighting_data)
{
	double	factor;

	factor = pow(calculation->reflect_eye_angle, \
		lighting_data->material.shininess);
	*light = vec3_add(*light, vec3_smultiply(lighting_data->light_source.color, \
		lighting_data->material.specular * factor));
}
