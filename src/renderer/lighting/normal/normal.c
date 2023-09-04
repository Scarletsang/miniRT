/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:43:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 20:07:17 by htsang           ###   ########.fr       */
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

t_mrt_vec3	mrt_lighting_normal_at_cylinder(struct s_mrt_cylinder *cylinder, \
t_mrt_vec3 world_point)
{
	return (vec3_normalize(\
		vec3_subtract(world_point, cylinder->scene->center)));
}

t_mrt_vec3	mrt_lighting_normal_at(struct s_mrt_world_entry object, \
t_mrt_vec3 world_point)
{
	if (object.identifier == ENTRY_SPHERE)
		return (mrt_lighting_normal_at_sphere(\
			object.object.sphere, world_point));
	else if (object.identifier == ENTRY_PLANE)
		return (mrt_lighting_normal_at_plane(\
			object.object.plane, world_point));
	else if (object.identifier == ENTRY_CYLINDER)
		return (mrt_lighting_normal_at_cylinder(\
			object.object.cylinder, world_point));
	else
		return (vec3(0, 0, 0));
}
