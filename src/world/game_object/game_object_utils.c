/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:00:46 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/04 14:33:39 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include <stdbool.h>

t_mrt_direction3d_unit	cylinder_normal_at_cap(struct s_mrt_scene_cylinder \
*scene, t_mrt_point3d intersection, t_mrt_point3d center)
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

t_mrt_direction3d_unit	cylinder_normal_at(struct s_mrt_scene_cylinder *scene, \
t_mrt_point3d intersection)
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
	bottom_point = vec3_add(intersection, vec3_multiply(orientation, t));
	normal = vec3_normalize(vec3_subtract(bottom_point, scene->center));
	return (normal);
}

t_mrt_direction3d_unit	mrt_normal_at(struct s_mrt_world_entry *entry, \
t_mrt_point3d point)
{
	t_mrt_direction3d_unit		normal;
	t_mrt_point3d				cylinder_top_center;
	struct s_mrt_scene_cylinder	*scene;

	if (entry->identifier == ENTRY_PLANE)
		return (entry->object.plane->scene->normal);
	else if (entry->identifier == ENTRY_SPHERE)
		return (vec3_normalize \
		(vec3_subtract(point, entry->object.sphere->scene->center)));
	else if (entry->identifier == ENTRY_CYLINDER)
	{
		scene = entry->object.cylinder->scene;
		cylinder_top_center = vec3(\
		scene->center.x + scene->height * scene->orientation.x, \
		scene->center.y + scene->height * scene->orientation.y, \
		scene->center.z + scene->height * scene->orientation.z);
		normal = cylinder_normal_at_cap(scene, point, cylinder_top_center);
		if (!vec3_is_zero(normal))
			return (normal);
		else
			return (cylinder_normal_at(scene, point));
	}
	else
		return (vec3_return_zero());
}

/**
 * Plan for finding the normal of a point on a Cylinder:
 * 1. If the point is on one of the caps
 * 	a: I can just use Orientation or -Orientation
 * 	b: To check if point is on caps, I can implement something like
 * 	   the intersect_caps function in cylinder.c
 * 2. Else, if the point is not on the caps
 * 	a: I can find a calculation to bring the point to the same axis
 * 	   as Center, then draw a vector from center to point
 *
 * Notes for 2:
 * Given; A: intersection point, C: Cylinder Center, O: Orientation (, radius)
 * Searching for: B: A, translated to be on same axis as C
 *
 * Observations:
 * - The vector from C to B should be orthogonal to O.
 * - B is A shifted in the minus O direction
 *
 * dot(B - C, O) = 0
 * ((B.x-C.x) * O.x + (B.y-C.y) * O.y + (B.z-C.z) * O.z) = 0
 *
 * B = A + t * (-O)
 *
 * Formula
 * ChatGPT:
 * k = - (A · A + O · A - C · A) / (A · O + O · O - C · O)
 *
 * Could also just use line circle intersection calculation
*/