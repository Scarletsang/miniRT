/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:09:52 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 11:31:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/range.h"

t_mrt_range	mrt_range(double min, double max)
{
	if (min > max)
		return ((t_mrt_range){max, min});
	return ((t_mrt_range){min, max});
}

double	mrt_range_minimum(t_mrt_range range)
{
	return (range.x);
}

double	mrt_range_maximum(t_mrt_range range)
{
	return (range.y);
}

double	mrt_range_size(t_mrt_range range)
{
	return (mrt_range_maximum(range) - mrt_range_minimum(range));
}
