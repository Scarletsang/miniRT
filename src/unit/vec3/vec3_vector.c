/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:45:39 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/06 06:32:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/vec3.h"

inline t_mrt_vec3	vec3_negate(t_mrt_vec3 v)
{
	return ((t_mrt_vec3){\
		.x = -v.x, \
		.y = -v.y, \
		.z = -v.z \
	});
}

inline t_mrt_vec3	vec3_add(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	return ((t_mrt_vec3){\
		.x = v1.x + v2.x, \
		.y = v1.y + v2.y, \
		.z = v1.z + v2.z \
	});
}

inline t_mrt_vec3	vec3_subtract(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	return ((t_mrt_vec3){\
		.x = v1.x - v2.x, \
		.y = v1.y - v2.y, \
		.z = v1.z - v2.z \
	});
}

inline t_mrt_vec3	vec3_multiply(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	return ((t_mrt_vec3){\
		.x = v1.x * v2.x, \
		.y = v1.y * v2.y, \
		.z = v1.z * v2.z \
	});
}

inline t_mrt_vec3	vec3_divide(t_mrt_vec3 v1, t_mrt_vec3 v2)
{
	return ((t_mrt_vec3){\
		.x = v1.x / v2.x, \
		.y = v1.y / v2.y, \
		.z = v1.z / v2.z \
	});
}
