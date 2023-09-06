/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:43:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 06:07:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"

t_mrt_vec3	mrt_lighting_normal_at_sphere(struct s_mrt_sphere *sphere, \
t_mrt_vec3 world_point)
{
	return (vec3_normalize(vec3_subtract(world_point, sphere->scene->center)));
}

t_mrt_vec3	mrt_lighting_normal_at_plane(struct s_mrt_plane *plane, \
t_mrt_vec3 world_point)
{
	(void) world_point;
	return (plane->scene->normal);
}
