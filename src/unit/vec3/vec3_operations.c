/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:45:39 by kisikogl          #+#    #+#             */
/*   Updated: 2023/07/26 10:48:04 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/vec3.h"

t_mrt_vec3	vec3_negate(t_mrt_vec3 v) {
	t_mrt_vec3	temp;

	temp.x = -v.x;
	temp.y = -v.y;
	temp.z = -v.z;
	return (temp);
}

t_mrt_vec3	vec3_add(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	t_mrt_vec3	temp;

	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	temp.z = v1.z + v2.z;
	return (temp);
}

t_mrt_vec3	vec3_subtract(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	t_mrt_vec3	temp;

	temp.x = v1.x - v2.x;
	temp.y = v1.y - v2.y;
	temp.z = v1.z - v2.z;
	return (temp);
}

t_mrt_vec3	vec3_multiply(t_mrt_vec3 v, double t)
{
	t_mrt_vec3	temp;

	temp.x = v.x * t;
	temp.y = v.y * t;
	temp.z = v.z * t;
	return (temp);
}

t_mrt_vec3	vec3_divide(t_mrt_vec3 v, double t)
{
	t_mrt_vec3	temp;

	temp.x = v.x / t;
	temp.y = v.y / t;
	temp.z = v.z / t;
	return (temp);
}