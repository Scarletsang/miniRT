/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:43:52 by kisikogl          #+#    #+#             */
/*   Updated: 2023/07/27 11:56:56 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/vec3.h"
#include <math.h>

double	vec3_length(const t_mrt_vec3 v) {

	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
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
	t_mrt_vec3_unit	temp;

	temp.x = v.x / vec3_length(v);
	temp.y = v.y / vec3_length(v);
	temp.z = v.z / vec3_length(v);
	return (temp);
}