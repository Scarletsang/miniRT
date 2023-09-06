/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 06:27:20 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 12:51:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit.h"
#include <math.h>

inline bool	mrt_double_is_equal(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

double	mrt_double_min(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	mrt_double_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
