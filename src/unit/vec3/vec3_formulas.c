/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:43:52 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/01 10:33:30 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/vec3.h"
#include <math.h>

double	vec3_length(const t_mrt_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	vec3_dot(const t_mrt_vec3 v1, const t_mrt_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_mrt_vec3	vec3_cross(const t_mrt_vec3 v1, const t_mrt_vec3 v2)
{
	t_mrt_vec3	temp;

	temp.x = v1.y * v2.z - v1.z * v2.y;
	temp.y = v1.z * v2.x - v1.x * v2.z;
	temp.z = v1.x * v2.y - v1.y * v2.x;
	return (temp);
}

t_mrt_vec3_unit	vec3_normalize(const t_mrt_vec3 v)
{
	double	length;

	length = vec3_length(v);
	if (length <= 0)
	{
		return ((t_mrt_vec3_unit){
		.x = 0,
		.y = 0,
		.z = 0});
	}
	else
	{
		return ((t_mrt_vec3_unit){
		.x = v.x / length,
		.y = v.y / length,
		.z = v.z / length});
	}
}
