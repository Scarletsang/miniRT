/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction3d_unit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:33:18 by htsang            #+#    #+#             */
/*   Updated: 2023/08/07 19:36:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit.h"

t_mrt_point3d	mrt_point3d_origin(void)
{
	return ((t_mrt_point3d){0, 0, 0});
}

t_mrt_direction3d_unit	mrt_direction3d_unit_empty(void)
{
	return ((t_mrt_direction3d_unit){0, 0, 0});
}

bool	mrt_direction3d_unit_is_empty(t_mrt_direction3d_unit *unit)
{
	return (unit->x == 0 && unit->y == 0 && unit->z == 0);
}
