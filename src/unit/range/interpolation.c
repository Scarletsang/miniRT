/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:59:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/07 20:36:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit.h"

double	mrt_lerp(t_mrt_range range, double percentage)
{
	return (mrt_range_size(range) * percentage + mrt_range_minimum(range));
}

double	mrt_inverse_lerp(t_mrt_range range, double value)
{
	return ((value - mrt_range_minimum(range)) / mrt_range_size(range));
}

double	mrt_remap(t_mrt_range input_range, t_mrt_range output_range, \
double value)
{
	double	percentage;

	percentage = mrt_inverse_lerp(input_range, value);
	return (mrt_lerp(output_range, percentage));
}
