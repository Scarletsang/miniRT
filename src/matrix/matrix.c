/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:49:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 17:51:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/memory.h"
#include <assert.h>

inline t_mrt_vec4	vec4(double x, double y, double z, double w)
{
	return ((t_mrt_vec4){\
		.x = x, \
		.y = y, \
		.z = z, \
		.w = w
	});
}
