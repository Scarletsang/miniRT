/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:49:24 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 17:13:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/color.h"
#include "MINIRT/unit/range.h"

t_mrt_vec3_unit	mrt_color_unit(t_mrt_color color)
{
	t_mrt_range	color_range;
	t_mrt_range	unit_range;

	color_range = mrt_range(0, 255);
	unit_range = mrt_range(0, 1);
	return ((t_mrt_vec3_unit){\
		.x = mrt_remap(color_range, unit_range, color.x), \
		.y = mrt_remap(color_range, unit_range, color.y), \
		.z = mrt_remap(color_range, unit_range, color.z), \
	});
}

t_mrt_color	mrt_vec3_unit_color(t_mrt_vec3_unit unit)
{
	t_mrt_range	color_range;
	t_mrt_range	unit_range;

	color_range = mrt_range(0, 255);
	unit_range = mrt_range(-1, 1);
	return ((t_mrt_color){\
		.x = mrt_remap(unit_range, color_range, unit.x), \
		.y = mrt_remap(unit_range, color_range, unit.y), \
		.z = mrt_remap(unit_range, color_range, unit.z), \
	});
}
