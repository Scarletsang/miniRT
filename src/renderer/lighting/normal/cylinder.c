/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:09:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 13:28:55 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"
#include "MINIRT/unit.h"

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

bool	mrt_lighting_is_camera_inside_cylinder( \
struct s_mrt_cylinder *cylinder, struct s_mrt_ray *ray)
{
	t_mrt_point3d	end_center;
	t_mrt_vec3		center_to_ray;
	t_mrt_vec3		center_to_end_center;
	t_mrt_vec3		end_center_to_ray;
	double			cross_length;

	end_center = vec3_add(cylinder->scene->center, \
		vec3_smultiply(cylinder->scene->orientation, cylinder->scene->height));
	center_to_ray = vec3_subtract(ray->origin, cylinder->scene->center);
	center_to_end_center = vec3_subtract(end_center, cylinder->scene->center);
	end_center_to_ray = vec3_subtract(ray->origin, end_center);
	if (vec3_dot(center_to_ray, center_to_end_center) >= 0 && \
		vec3_dot(end_center_to_ray, center_to_end_center) <= 0)
	{
		cross_length = vec3_length(\
			vec3_cross(center_to_ray, center_to_end_center));
		if ((cross_length / vec3_length(center_to_end_center)) <= \
			(cylinder->scene->diameter / 2))
			return (true);
	}
	return (false);
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
