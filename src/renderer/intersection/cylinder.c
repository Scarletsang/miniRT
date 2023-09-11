/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:02:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 21:53:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/renderer/ray.h"
#include <stdbool.h>
#include <math.h>

/**
 * Check here if ray intersects with Cap.
 * After the first point is out of range, there are three possibilities:
 * 1. The second point is out of range and in between lies nothing.
 * 2. The second point is out of range but in between is the cap.
 * 3. The second point is in range, and it went through the cap.
 *
 * Approach idea 1 (do the same for Start):
 * Use this formula to get t. t will help to easily find
 * the cap intersection point.
 * P = r.origin + t * r.direction
 * t = P / r.direction - r.origin`
 * to determine P, calculate on which point the ray is
 * on the same "Y" value as End, if any;
 * Of course, the "Y" value is not always actually y.
 * Use orientation to determine what it is.
 * P = {x, 5, z}
 *
 * Approach idea 2 (do the same for Start):
 * Create a plane which represent the cap:
 * the point is End and the normal is orientation.
 * Get the point in which the ray and plane intersects.
 * Check if it's inside of the cylinder:
 * Draw a vector from intersection point to End.
 * Is it's length <= cylinder radius? Render. No? Disimss
 *
 * https://www.math3d.org/TDdXCmoIU
*/

static void	intersect_caps(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, t_mrt_point3d plane_point, t_mrt_vec2 *roots)
{
	double			distance;
	double			t;
	t_mrt_vec3		tmp;

	tmp = vec3_subtract(plane_point, ray->origin);
	t = vec3_dot(ray->direction, cylinder->scene->orientation);
	if (t == 0)
		return ;
	t = vec3_dot(tmp, vec3_sdivide(cylinder->scene->orientation, t));
	if (t < 0)
		return ;
	if (!vec3_is_equal(plane_point, cylinder->scene->center))
		intersect_caps(ray, cylinder, cylinder->scene->center, roots);
	distance = vec3_length(vec3_subtract(ray_at(ray, t), plane_point));
	if (distance <= (cylinder->scene->diameter / 2))
	{
		if (roots->x < 0 || t < roots->x)
			roots->x = t;
		else if (roots->y < 0 || t < roots->y)
			roots->y = t;
	}
}

static void	is_in_range(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
t_mrt_vec2 *roots)
{
	t_mrt_direction3d	orientation;
	t_mrt_point3d		start;
	t_mrt_point3d		end;
	t_mrt_vec3			pos_start;
	t_mrt_vec3			pos_end;

	orientation = cylinder->scene->orientation;
	start = cylinder->scene->center;
	end = vec3_add(start, vec3_smultiply(orientation, cylinder->scene->height));
	if (roots->x < 0 && roots->y < 0)
	{
		intersect_caps(ray, cylinder, end, roots);
		return ;
	}
	pos_start = vec3_subtract(start, ray_at(ray, roots->y));
	pos_end = vec3_subtract(end, ray_at(ray, roots->y));
	if (!(vec3_dot(pos_start, orientation) <= 0 && \
		vec3_dot(pos_end, orientation) >= 0))
		roots->y = -1;
	pos_start = vec3_subtract(start, ray_at(ray, roots->x));
	pos_end = vec3_subtract(end, ray_at(ray, roots->x));
	if (!(vec3_dot(pos_start, orientation) <= 0 && \
		vec3_dot(pos_end, orientation) >= 0))
		roots->x = -1;
	intersect_caps(ray, cylinder, end, roots);
}

/**
 * Formula for ray cylinder intersection:
 *
 * D: ray_direction
 * V: unit length vector of cylinder axis
 * X: O - C (ray_origin - start cap point of cylinder)
 * r: radius
 *
 * a   = D|D - (D|V)^2
 * b/2 = D|X - (D|V)*(X|V)
 * c   = X|X - (X|V)^2 - r*r
 * discriminant = b*b - 4ac
*/

double	mrt_intersect_cylinder(struct s_mrt_cylinder *cylinder, \
struct s_mrt_ray *ray)
{
	t_mrt_vec3	x;
	t_mrt_vec3	quadratic;
	double		tmp;
	t_mrt_vec2	roots;

	x = vec3_subtract(ray->origin, cylinder->scene->center);
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	quadratic.x = vec3_dot(ray->direction, ray->direction) - (tmp * tmp);
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	tmp = tmp * vec3_dot(x, cylinder->scene->orientation);
	quadratic.y = (vec3_dot(ray->direction, x) - tmp) * 2;
	tmp = vec3_dot(x, cylinder->scene->orientation);
	quadratic.z = vec3_dot(x, x) - tmp * tmp - \
		(cylinder->scene->diameter / 2) * (cylinder->scene->diameter / 2);
	tmp = mrt_quadratic_discriminant(quadratic);
	roots = mrt_quadratic_roots(quadratic, tmp);
	if (tmp < 0)
		return (-1);
	is_in_range(ray, cylinder, &roots);
	return (mrt_quadratic_smallest_root(roots));
}

/*
Plan for truncating + capping the cylinder:
Get the intersection point P.
	Formula for the 2 intersection points, I guess:
		t0 ← (-b - √(disc)) / (2 * a)
		t1 ← (-b + √(disc)) / (2 * a)
Draw a Vector V from P to Center (Center - P)
Calculate if V is rather in the direction of orientation
	or in the direction of -orientaion?
If it's rather in the direction of -orientation, render it
If it's equal to both directions, render it
If it's rather in the direction of orientation, dismiss
*/

/* Paper bin:

double	intersect_caps_working_longer_version(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, t_mrt_point3d start, t_mrt_point3d end)
{
	struct s_mrt_plane			*pln;
	struct s_mrt_scene_plane	scene_pln;
	t_mrt_point3d				intersection;
	double						distance;

	scene_pln.point = end;
	scene_pln.normal = cylinder->scene->orientation;
	scene_pln.color = (vec3(0.0, 0.0, 0.0));
	pln = mrt_plane(&scene_pln);
	intersection = ray_at(ray, mrt_plane_get_t_intersection(ray, pln));
	distance = vec3_length(vec3_subtract(end, intersection));
	free(pln);
	if (distance <= (cylinder->scene->diameter / 2))
		return (vec3_length(vec3_subtract(intersection, ray->origin)));
	scene_pln.point = start;
	pln = mrt_plane(&scene_pln);
	intersection = ray_at(ray, mrt_plane_get_t_intersection(ray, pln));
	distance = vec3_length(vec3_subtract(start, intersection));
	free(pln);
	if (distance <= (cylinder->scene->diameter / 2))
		return(vec3_length(vec3_subtract(intersection, ray->origin)));
	return (0);
}

dependency for above:
double	mrt_plane_get_t_intersection(\
struct s_mrt_ray *ray, struct s_mrt_plane *plane)
{
	t_mrt_vec3	tmp;
	double		t;

	tmp = vec3_subtract(plane->scene->point, ray->origin);
	t = vec3_dot(ray->direction, plane->scene->normal);
	if (t == 0)
		return (0);
	t = vec3_dot(tmp, vec3_divide(plane->scene->normal, t));
	if (t < 0)
		return (0);
	return (t);
}

intersect Caps tests:
if (a % 4624903 == 0)
{
	printf("ray->origin: %f, %f, %f\n", \
	ray->origin.x, ray->origin.y, ray->origin.z);
	printf("ray->direction: %f, %f, %f\n", \
	ray->direction.x, ray->direction.y, ray->direction.z);
	printf("end: %f, %f, %f\n", end.x, end.y, end.z);
	// if (intersection.x > 0 || intersection.y > 0 || intersection.z > 0)
		printf("intersection: %f, %f, %f\n", \
		intersection.x, intersection.y, intersection.z);
	printf("distance: %f\n", distance);
}
a++;

bool	is_in_range2(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
double t0, double t1)
{
	t_mrt_vec3			pc0;
	t_mrt_vec3			pc1;
	t_mrt_point3d		p0;
	t_mrt_point3d		p1;
	t_mrt_direction3d	o;
	double				angle;
	double				angle2;

	p0 = ray_at(ray, t0);
	p1 = ray_at(ray, t1);
	pc0 = vec3_subtract(cylinder->scene->center, p0);
	pc1 = vec3_subtract(cylinder->scene->center, p1);
	o = cylinder->scene->orientation;
	angle = acos(vec3_dot(pc0, o) / (vec3_length(pc0) * vec3_length(o)));
	o = vec3_negate(o);
	angle2 = acos(vec3_dot(pc0, o) / (vec3_length(pc0) * vec3_length(o)));
	if (angle2 <= angle)
		return (true);
	return (false);
}

bool	is_in_range_book(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, double t0, double t1)
{
	double	y0;
	double	y1;
	double	min;
	double	max;

	y0 = ray->origin.y + t0 * ray->direction.y;
	y1 = ray->origin.y + t1 * ray->direction.y;
	min = cylinder->scene->center.y;
	max = cylinder->scene->center.y + cylinder->scene->height;
	if (min < y0 && y0 < max)
		return (true);
	if (min < y1 && y1 < max)
		return (true);
	return (false);
}



bool	is_in_range_my_formula(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, double t0, double t1)
{
	t_mrt_point3d	p0;
	t_mrt_point3d	p1;
	t_mrt_point3d	start;
	t_mrt_point3d	end;
	double			tx;
	double			ty;
	double			tz;
	double			ox;
	double			oy;
	double			oz;
	double			h2;

	tx = 0;
	ty = 0;
	tz = 0;
	ox = cylinder->scene->orientation.x;
	oy = cylinder->scene->orientation.y;
	oz = cylinder->scene->orientation.z;
	h2 = cylinder->scene->height * cylinder ->scene->height;
	if (ox != 0)
		tx = sqrt((h2 / (ox + oy + oz)) / ox);
	if (oy != 0)
		ty = sqrt((h2 / (ox + oy + oz)) / oy);
	if (oz != 0)
		tz = sqrt((h2 / (ox + oy + oz)) / oz);
	start = cylinder->scene->center;
	end = vec3(tx * ox, ty * oy, tz * oz);
	end = vec3_add(start, end);
	p0 = ray_at(ray, t0);
	p1 = ray_at(ray, t1);
	if (((p0.x >= start.x && p0.x <= end.x) || \
	(p0.x <= start.x && p0.x >= end.x) || (start.x == end.x)) && \
	((p0.y >= start.y && p0.y <= end.y) || \
	(p0.y <= start.y && p0.y >= end.y) || (start.y == end.y)) && \
	((p0.z >= start.z && p0.z <= end.z) || \
	(p0.z <= start.z && p0.z >= end.z) || (start.z == end.z)))
		return (true);
	if (((p1.x >= start.x && p1.x <= end.x) || \
	(p1.x <= start.x && p1.x >= end.x) || (start.x == end.x)) && \
	((p1.y >= start.y && p1.y <= end.y) || \
	(p1.y <= start.y && p1.y >= end.y) || (start.y == end.y)) && \
 	((p1.z >= start.z && p1.z <= end.z) || \
	(p1.z <= start.z && p1.z >= end.z) || (start.z == end.z)))
		return (true);
	return (false);
}

bool	is_in_range_bookinternet(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, double t0, double t1)
{
	t_mrt_point3d	p0;
	t_mrt_point3d	p1;
	t_mrt_point3d	start;
	t_mrt_point3d	end;

	p0 = ray_at(ray, t0);
	p1 = ray_at(ray, t1);
	start = cylinder->scene->center;
	end = vec3( \
	start.x + cylinder->scene->height * cylinder->scene->orientation.x, \
	start.y + cylinder->scene->height * cylinder->scene->orientation.y, \
	start.z + cylinder->scene->height * cylinder->scene->orientation.z);
	if (((p0.x >= start.x && p0.x <= end.x) || \
	(p0.x <= start.x && p0.x >= end.x) || (start.x == end.x)) && \
	((p0.y >= start.y && p0.y <= end.y) || \
	(p0.y <= start.y && p0.y >= end.y) || (start.y == end.y)) && \
	((p0.z >= start.z && p0.z <= end.z) || \
	(p0.z <= start.z && p0.z >= end.z) || (start.z == end.z)))
		return (true);
	if (((p1.x >= start.x && p1.x <= end.x) || \
	(p1.x <= start.x && p1.x >= end.x) || (start.x == end.x)) && \
	((p1.y >= start.y && p1.y <= end.y) || \
	(p1.y <= start.y && p1.y >= end.y) || (start.y == end.y)) && \
 	((p1.z >= start.z && p1.z <= end.z) || \
	p1.z <= start.z && p1.z >= end.z) || (start.z == end.z)))
		return (true);
	return (false);
}

bool	mrt_cylinder_is_hit_book(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	t0;
	double	t1;

	a = ray->direction.x * ray->direction.x;
	a = a + ray->direction.z * ray->direction.z;
	if (fabs(a) < 0.2)
		return (false);
	b = 2 * ray->origin.x * ray->direction.x;
	b = b + 2 * ray->origin.z * ray->direction.z;
	c = ray->origin.x * ray->origin.x;
	c = c + ray->origin.z * ray->origin.z - \
	(cylinder->scene->diameter / 2) * (cylinder->scene->diameter / 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (false);
	t0 = (-b - sqrt(disc)) / (2 * a);
	t1 = (-b + sqrt(disc)) / (2 * a);
	return (is_in_range(ray, cylinder, t0, t1));
}

bool	intersect_caps_book(struct s_mrt_ray *ray, double min, double max)
{
	double	t;
	double	x;
	double	z;

	if (fabs(ray->direction.y) < 0.2)
		return (false);
	t = (min - ray->origin.y) / ray->direction.y;
	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	if ((x * x + z * z) <= 1)
		return (true);
	t = (max - ray->origin.y) / ray->direction.y;
	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	if ((x * x + z * z) <= 1)
		return (true);
	return (false);
}


*/
