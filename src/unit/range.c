/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:09:52 by htsang            #+#    #+#             */
/*   Updated: 2023/06/23 00:14:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/range.h"

t_mrt_range	mrt_range(float min, float max)
{
	if (min > max)
		return ((t_mrt_range){max, min});
	return ((t_mrt_range){min, max});
}

float	mrt_range_minimum(t_mrt_range range)
{
	return (range.x);
}

float	mrt_range_maximum(t_mrt_range range)
{
	return (range.y);
}

float	mrt_range_size(t_mrt_range range)
{
	return (mrt_range_maximum(range) - mrt_range_minimum(range));
}
