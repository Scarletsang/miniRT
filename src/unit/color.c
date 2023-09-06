/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:49:24 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 12:54:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/color.h"
#include "MINIRT/unit/range.h"
#include "MINIRT/unit.h"

inline t_mrt_percentage	mrt_color_to_percentage(t_mrt_color color)
{
	return (vec3_remap(mrt_range(0, 255), mrt_range(0, 1), color));
}

inline t_mrt_color	mrt_percentage_to_color(t_mrt_percentage percentage)
{
	return (vec3_remap(mrt_range(0, 1), mrt_range(0, 255), percentage));
}

inline t_mrt_color	mrt_vec3_unit_to_color(t_mrt_vec3_unit unit)
{
	return (vec3_remap(mrt_range(-1, 1), mrt_range(0, 255), unit));
}

inline t_mrt_percentage	mrt_percentage_clamp(t_mrt_percentage percentage)
{
	return ((t_mrt_percentage){
		.x = mrt_double_min(1.0, mrt_double_max(0.0, percentage.x)),
		.y = mrt_double_min(1.0, mrt_double_max(0.0, percentage.y)),
		.z = mrt_double_min(1.0, mrt_double_max(0.0, percentage.z))
	});
}
