/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:09:52 by htsang            #+#    #+#             */
/*   Updated: 2023/08/17 13:36:01 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit/range.h"

t_mrt_range	mrt_range(double min, double max)
{
	return ((t_mrt_range){min, max});
}

double	mrt_range_minimum(t_mrt_range range)
{
	if (range.x <= range.y)
		return (range.x);
	else
		return (range.y);
}

double	mrt_range_maximum(t_mrt_range range)
{
	if (range.x > range.y)
		return (range.x);
	else
		return (range.y);
}

double	mrt_range_size(t_mrt_range range)
{
	return (mrt_range_maximum(range) - mrt_range_minimum(range));
}
