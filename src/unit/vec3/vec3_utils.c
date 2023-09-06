/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:09 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/06 06:33:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit.h"
#include <stdio.h>
#include <stdbool.h>

inline t_mrt_vec3	vec3(double x, double y, double z)
{
	return ((t_mrt_vec3){\
		.x = x, \
		.y = y, \
		.z = z});
}

inline t_mrt_vec3	vec3_return_zero(void)
{
	return ((t_mrt_vec3){.x = 0, .y = 0, .z = 0});
}

inline bool	vec3_is_zero(t_mrt_vec3 v)
{
	return (v.x == 0 && v.y == 0 && v.z == 0);
}

inline bool	vec3_is_equal(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	return (mrt_double_is_equal(v1.x, v2.x) && \
		mrt_double_is_equal(v1.y, v2.y) && \
		mrt_double_is_equal(v1.z, v2.z));
}

inline void	vec3_print(t_mrt_vec3 v)
{
	printf("x: %f, y: %f, z: %f\n", v.x, v.y, v.z);
}
