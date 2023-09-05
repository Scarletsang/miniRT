/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:09:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 23:19:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"

static t_mrt_direction3d_unit	cylinder_normal_at_cap(\
struct s_mrt_scene_cylinder *scene, t_mrt_point3d intersection, \
t_mrt_point3d center)
{
	double			distance;

	distance = vec3_length(vec3_subtract(center, intersection));
	if (distance <= (scene->diameter / 2))
	{
		if (vec3_is_equal(center, scene->center))
			return (vec3_negate(scene->orientation));
		else
			return (scene->orientation);
	}
	else if (!vec3_is_equal(center, scene->center))
		return (cylinder_normal_at_cap(scene, intersection, scene->center));
	else
		return (vec3_return_zero());
}

static t_mrt_direction3d_unit	cylinder_normal_at(\
struct s_mrt_scene_cylinder *scene, t_mrt_point3d intersection)
{
	t_mrt_direction3d_unit	normal;
	t_mrt_direction3d_unit	orientation;
	t_mrt_point3d			bottom_point;
	double					t;
	double					tmp;

	orientation = vec3_negate(scene->orientation);
	tmp = vec3_dot(orientation, intersection);
	t = vec3_dot(intersection, intersection) + tmp;
	t = t - vec3_dot(scene->center, intersection);
	tmp = tmp + vec3_dot(orientation, orientation);
	tmp = tmp - vec3_dot(scene->center, orientation);
	t = - (t) / tmp;
	bottom_point = vec3_add(intersection, vec3_smultiply(orientation, t));
	normal = vec3_normalize(vec3_subtract(bottom_point, scene->center));
	return (normal);
}

t_mrt_vec3	mrt_lighting_normal_at_cylinder(struct s_mrt_cylinder *cylinder, \
t_mrt_vec3 world_point)
{
	t_mrt_direction3d_unit		normal;
	struct s_mrt_scene_cylinder	*scene;
	t_mrt_point3d				cylinder_top_center;

	scene = cylinder->scene;
	cylinder_top_center = vec3_add(\
		vec3_smultiply(scene->orientation, scene->height), \
		scene->center);
	normal = cylinder_normal_at_cap(scene, world_point, cylinder_top_center);
	if (!vec3_is_zero(normal))
		return (normal);
	else
		return (cylinder_normal_at(scene, world_point));
}
