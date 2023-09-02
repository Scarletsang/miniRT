/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scalar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:45:39 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/02 15:00:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/vec3.h"

t_mrt_vec3	vec3_sadd(t_mrt_vec3 v, double t)
{
	return ((t_mrt_vec3){\
		.x = v.x + t, \
		.y = v.y + t, \
		.z = v.z + t \
	});
}

t_mrt_vec3	vec3_ssubtract(t_mrt_vec3 v, double t)
{
	return ((t_mrt_vec3){\
		.x = v.x - t, \
		.y = v.y - t, \
		.z = v.z - t \
	});
}

t_mrt_vec3	vec3_smultiply(t_mrt_vec3 v, double t)
{
	return ((t_mrt_vec3){\
		.x = v.x * t, \
		.y = v.y * t, \
		.z = v.z * t \
	});
}

t_mrt_vec3	vec3_sdivide(t_mrt_vec3 v, double t)
{
	return ((t_mrt_vec3){\
		.x = v.x / t, \
		.y = v.y / t, \
		.z = v.z / t \
	});
}
