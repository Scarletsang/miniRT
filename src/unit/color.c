/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 16:49:24 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 06:31:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/color.h"
#include "MINIRT/unit/range.h"
#include "MINIRT/unit.h"

inline t_mrt_color_unit	mrt_color_to_color_unit(t_mrt_color color)
{
	return (vec3_remap(mrt_range(0, 255), mrt_range(0, 1), color));
}

inline t_mrt_color	mrt_color_unit_to_color(t_mrt_color_unit color_unit)
{
	return (vec3_remap(mrt_range(0, 1), mrt_range(0, 255), color_unit));
}

inline t_mrt_color	mrt_vec3_unit_to_color(t_mrt_vec3_unit unit)
{
	return (vec3_remap(mrt_range(-1, 1), mrt_range(0, 255), unit));
}
