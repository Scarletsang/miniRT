/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:43:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 13:29:02 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"
#include "MINIRT/unit.h"

t_mrt_vec3	mrt_lighting_normal_at_plane(struct s_mrt_plane *plane, \
t_mrt_vec3 world_point)
{
	(void) world_point;
	return (plane->scene->normal);
}

t_mrt_vec3	mrt_lighting_normal_at_sphere(struct s_mrt_sphere *sphere, \
t_mrt_vec3 world_point)
{
	return (vec3_normalize(vec3_subtract(world_point, sphere->scene->center)));
}

bool	mrt_lighting_is_camera_inside_sphere( \
struct s_mrt_sphere *sphere, struct s_mrt_ray *ray)
{
	double	distance;

	distance = vec3_length(vec3_subtract(ray->origin, sphere->scene->center));
	if (distance <= (sphere->scene->diameter / 2))
		return (true);
	else
		return (false);
}
