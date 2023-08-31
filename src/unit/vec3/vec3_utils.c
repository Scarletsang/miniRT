/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:09 by kisikogl          #+#    #+#             */
/*   Updated: 2023/08/31 18:11:57 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

t_mrt_vec3	vec3(double x, double y, double z)
{
	t_mrt_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

bool	vec3_is_equal(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	return (fabs(v1.x - v2.x) < 0.001 && fabs(v1.y - v2.y) < 0.001 && \
	fabs(v1.z - v2.z) < 0.001);
}

void	vec3_print(t_mrt_vec3 v)
{
	printf("x: %f, y: %f, z: %f\n", v.x, v.y, v.z);
}
