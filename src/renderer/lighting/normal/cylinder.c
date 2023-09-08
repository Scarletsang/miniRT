/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:09:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 21:54:00 by htsang           ###   ########.fr       */
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
		{
			if (distance < (vec3_length(\
			vec3_subtract(scene->center, intersection))))
				return (scene->orientation);
			else
				return (vec3_negate(scene->orientation));
		}
	}
	else if (!vec3_is_equal(center, scene->center))
		return (cylinder_normal_at_cap(scene, intersection, scene->center));
	else
		return (vec3_return_zero());
}

// static t_mrt_direction3d_unit	cylinder_normal_at2(
// struct s_mrt_scene_cylinder *scene, t_mrt_point3d intersection)
// {
// 	t_mrt_direction3d_unit	normal;
// 	t_mrt_direction3d_unit	orientation;
// 	t_mrt_point3d			bottom_point;
// 	double					t;
// 	double					tmp;

// 	orientation = vec3_negate(scene->orientation);
// 	tmp = vec3_dot(orientation, intersection);
// 	t = vec3_dot(intersection, intersection) + tmp;
// 	t = t - vec3_dot(scene->center, intersection);
// 	tmp = tmp + vec3_dot(orientation, orientation);
// 	tmp = tmp - vec3_dot(scene->center, orientation);
// 	t = - t / tmp;
// 	bottom_point = vec3_add(intersection, vec3_smultiply(orientation, t));
// 	normal = vec3_normalize(vec3_subtract(bottom_point, scene->center));
// 	return (normal);
// }

static t_mrt_direction3d_unit	cylinder_normal_at(\
struct s_mrt_scene_cylinder *scene, t_mrt_point3d intersection)
{
	double					t;
	t_mrt_direction3d		direction;
	t_mrt_vec3				tmp;

	tmp = vec3_subtract(scene->center, intersection);
	t = vec3_dot(vec3_negate(scene->orientation), scene->orientation);
	t = vec3_dot(tmp, vec3_sdivide(scene->orientation, t));
	if (t < 0)
		return (vec3_return_zero());
	direction = vec3_smultiply(vec3_negate(scene->orientation), t);
	tmp = vec3_subtract(vec3_add(intersection, direction), scene->center);
	return (vec3_normalize(tmp));
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
