/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:02:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 07:54:04 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/renderer/ray.h"
#include <stdbool.h>
#include <math.h>

/**
 *
 * Approach for capping the cylinder:
 *
 * 1. Create a plane which represent the cap.
 * 		The point is Center and the normal is negated Orientation.
 * 2. Get the point in which the ray and plane intersects (if at all).
 * 3. Check if it's inside of the cylinder.
 * 		Draw a vector from intersection point to Center.
 * 		Is it's length smaller or equal to cylinder radius? Render. No? Disimss.
 * 4. Repeat the process once, replacing center with end_center and configuring
 * 	the normal to be Orientation
*/

static void	intersect_caps(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, t_mrt_point3d center, t_mrt_vec2 *roots)
{
	double			distance;
	double			t;
	t_mrt_vec3		ray_to_center;

	ray_to_center = vec3_subtract(center, ray->origin);
	t = vec3_dot(ray->direction, cylinder->scene->orientation);
	if (t == 0)
		return ;
	t = vec3_dot(ray_to_center, vec3_sdivide(cylinder->scene->orientation, t));
	if (t < 0)
		return ;
	if (!vec3_is_equal(center, cylinder->scene->center))
		intersect_caps(ray, cylinder, cylinder->scene->center, roots);
	distance = vec3_length(vec3_subtract(ray_at(ray, t), center));
	if (distance <= (cylinder->scene->diameter / 2))
	{
		if (roots->x < 0 || t < roots->x)
			roots->x = t;
		else if (roots->y < 0 || t < roots->y)
			roots->y = t;
	}
}

/**
 * Formula for truncating the infinte long cylinder:
 *
 * Draw a Vector V from intersection point to Center.
 * Calculate the angle between V and the Normal vector at Center.
 * If it's smaller than 90 degrees, the intersection point is
 * outside of the cylidner.
 * Else, repeat the process once, replacing center with end_center.
 * If it's also greater or equal to 90 degrees there, it means that the point
 * is on the cylinder and we can render it.
 *
 * Repeat for both intersection points
*/

static void	is_in_range(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
t_mrt_vec2 *roots)
{
	t_mrt_point3d		center;
	t_mrt_point3d		end_center;
	t_mrt_vec3			insec_to_center;
	t_mrt_vec3			insec_to_end_center;

	center = cylinder->scene->center;
	end_center = vec3_add(center, \
		vec3_smultiply(cylinder->scene->orientation, cylinder->scene->height));
	if (roots->x < 0 && roots->y < 0)
	{
		intersect_caps(ray, cylinder, end_center, roots);
		return ;
	}
	insec_to_center = vec3_subtract(center, ray_at(ray, roots->y));
	insec_to_end_center = vec3_subtract(end_center, ray_at(ray, roots->y));
	if (!(vec3_dot(insec_to_center, cylinder->scene->orientation) <= 0 && \
		vec3_dot(insec_to_end_center, cylinder->scene->orientation) >= 0))
		roots->y = -1;
	insec_to_center = vec3_subtract(center, ray_at(ray, roots->x));
	insec_to_end_center = vec3_subtract(end_center, ray_at(ray, roots->x));
	if (!(vec3_dot(insec_to_center, cylinder->scene->orientation) <= 0 && \
		vec3_dot(insec_to_end_center, cylinder->scene->orientation) >= 0))
		roots->x = -1;
	intersect_caps(ray, cylinder, end_center, roots);
}

/**
 * Formula for ray intersection with an infinite long, uncapped cylinder:
 *
 * D: ray_direction
 * O: orientation
 * X: center_to_ray
 * r: radius
 *
 * a   = D . D - (D . O)^2
 * b/2 = D . X - (D . O) * (X . O)
 * c   = X . X - (X . O)^2 - r^2
 *
 * Apply the quadratic formula.
 *
 * discriminant = b^2 - 4 * a * c
*/

double	mrt_intersect_cylinder(struct s_mrt_cylinder *cylinder, \
struct s_mrt_ray *ray)
{
	t_mrt_vec3	center_to_ray;
	t_mrt_vec3	quadratic;
	double		tmp;
	double		discriminant;
	t_mrt_vec2	roots;

	center_to_ray = vec3_subtract(ray->origin, cylinder->scene->center);
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	quadratic.x = vec3_dot(ray->direction, ray->direction) - (tmp * tmp);
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	tmp = tmp * vec3_dot(center_to_ray, cylinder->scene->orientation);
	quadratic.y = (vec3_dot(ray->direction, center_to_ray) - tmp) * 2;
	tmp = vec3_dot(center_to_ray, cylinder->scene->orientation);
	quadratic.z = vec3_dot(center_to_ray, center_to_ray) - tmp * tmp - \
		(cylinder->scene->diameter / 2) * (cylinder->scene->diameter / 2);
	discriminant = mrt_quadratic_discriminant(quadratic);
	roots = mrt_quadratic_roots(quadratic, discriminant);
	if (discriminant < 0)
		return (-1);
	is_in_range(ray, cylinder, &roots);
	return (mrt_quadratic_smallest_root(roots));
}
