/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:41 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 16:11:55 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/ray.h"
#include "MINIRT/unit.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_cylinder)
{
	struct s_mrt_cylinder	*cyl;

	cyl = malloc(sizeof(struct s_mrt_cylinder));
	if (!cyl)
		return (NULL);
	scene_cylinder->orientation = vec3_normalize(scene_cylinder->orientation);
	*cyl = (struct s_mrt_cylinder){.scene = scene_cylinder};
	return (cyl);
}

/**
 * Check here if ray intersects with Cap.
 * After the first point is out of range, there are three possibilities:
 * 1. The second point is out of range and in between lies nothing.
 * 2. The second point is out of range but in between is the cap.
 * 3. The second point is in range, and it went through the cap.
 *
 * Approach idea 1 (do the same for Start):
 * Use this formula to get t. t will help to easily find the cap intersection point.
 * P = r.origin + t * r.direction
 * t = P / r.direction - r.origin
 * to determine P, calculate on which point the ray is on the same "Y" value as End, if any;
 * Of course, the "Y" value is not always actually y. Use orientation to determine what it is.
 * P = {x, 5, z}
 *
 * Approach idea 2 (do the same for Start):
 * Create a plane which represent the cap: the point is End and the normal is orientation.
 * Get the point in which the ray and plane intersects.
 * Check if it's inside of the cylinder:
 * Draw a vector from intersection point to End.
 * Is it's length <= cylinder radius? Render. No? Disimss
 *
 * https://www.math3d.org/TDdXCmoIU
*/

double	intersect_caps(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder, t_mrt_point3d plane_point)
{
	t_mrt_point3d	intersection;
	double			distance;
	double			t;
	t_mrt_vec3		tmp;

	tmp = vec3_subtract(plane_point, ray->origin);
	t = vec3_dot(ray->direction, cylinder->scene->orientation);
	if (t == 0)
		return (0);
	t = vec3_dot(tmp, vec3_divide(cylinder->scene->orientation, t));
	if (t < 0)
		return (0);
	intersection = ray_at(ray, t);
	distance = vec3_length(vec3_subtract(plane_point, intersection));
	if (distance <= (cylinder->scene->diameter / 2))
		return (vec3_length(vec3_subtract(intersection, ray->origin)));
	if (!vec3_is_equal(plane_point, cylinder->scene->center))
		return (intersect_caps(ray, cylinder, cylinder->scene->center));
	else
		return (0);
}

bool	is_in_range(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
double t0, double t1)
{
	t_mrt_vec3			pc_s;
	t_mrt_vec3			pc_e;
	t_mrt_point3d		p0;
	t_mrt_point3d		p1;
	t_mrt_point3d		start;
	t_mrt_point3d		end;
	t_mrt_direction3d	o;
	double				distance;

	start = cylinder->scene->center;
	end = vec3( \
	start.x + cylinder->scene->height * cylinder->scene->orientation.x, \
	start.y + cylinder->scene->height * cylinder->scene->orientation.y, \
	start.z + cylinder->scene->height * cylinder->scene->orientation.z);
	p0 = ray_at(ray, t0);
	p1 = ray_at(ray, t1);
	o = cylinder->scene->orientation;
	pc_s = vec3_subtract(start, p1);
	pc_e = vec3_subtract(end, p1);
	if (vec3_dot(pc_s, o) <= 0 && vec3_dot(pc_e, o) >= 0)
		return (true);
	distance = intersect_caps(ray, cylinder, end);
	if (distance > 0)
		return (true);
	pc_s = vec3_subtract(start, p0);
	pc_e = vec3_subtract(end, p0);
	if (vec3_dot(pc_s, o) <= 0 && vec3_dot(pc_e, o) >= 0)
		return (true);
	return (false);
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

bool	mrt_cylinder_is_hit(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder)
{
	t_mrt_vec3	x;
	double		r;
	double		a;
	double		b;
	double		c;
	double		disc;
	double		tmp;
	double		t0;
	double		t1;

	x = vec3_subtract(ray->origin, cylinder->scene->center);
	r = cylinder->scene->diameter / 2;
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	tmp = tmp * tmp;
	a = vec3_dot(ray->direction, ray->direction) - tmp;
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	tmp = tmp * vec3_dot(x, cylinder->scene->orientation);
	b = (vec3_dot(ray->direction, x) - tmp) * 2;
	tmp = vec3_dot(x, cylinder->scene->orientation);
	c = vec3_dot(x, x) - tmp * tmp - r * r;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (false);
	t0 = (-b - sqrt(disc)) / (2 * a);
	t1 = (-b + sqrt(disc)) / (2 * a);
	return (is_in_range(ray, cylinder, t0, t1));
}

void	mrt_cylinder_free(struct s_mrt_cylinder *cylinder)
{
	free(cylinder->scene);
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
	printf("ray->origin: %f, %f, %f\n", ray->origin.x, ray->origin.y, ray->origin.z);
	printf("ray->direction: %f, %f, %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
	printf("end: %f, %f, %f\n", end.x, end.y, end.z);
	// if (intersection.x > 0 || intersection.y > 0 || intersection.z > 0)
		printf("intersection: %f, %f, %f\n", intersection.x, intersection.y, intersection.z);
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

bool	is_in_range_book(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
double t0, double t1)
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



bool	is_in_range_my_formula(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
double t0, double t1)
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
	if (((p0.x >= start.x && p0.x <= end.x) || (p0.x <= start.x && p0.x >= end.x) || (start.x == end.x)) && \
	((p0.y >= start.y && p0.y <= end.y) || (p0.y <= start.y && p0.y >= end.y) || (start.y == end.y)) && \
	((p0.z >= start.z && p0.z <= end.z) || (p0.z <= start.z && p0.z >= end.z) || (start.z == end.z)))
		return (true);
	if (((p1.x >= start.x && p1.x <= end.x) || (p1.x <= start.x && p1.x >= end.x) || (start.x == end.x)) && \
	((p1.y >= start.y && p1.y <= end.y) || (p1.y <= start.y && p1.y >= end.y) || (start.y == end.y)) && \
 	((p1.z >= start.z && p1.z <= end.z) || (p1.z <= start.z && p1.z >= end.z) || (start.z == end.z)))
		return (true);
	return (false);
}

bool	is_in_range_bookinternet(struct s_mrt_ray *ray, struct s_mrt_cylinder *cylinder, \
double t0, double t1)
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
	if (((p0.x >= start.x && p0.x <= end.x) || (p0.x <= start.x && p0.x >= end.x) || (start.x == end.x)) && \
	((p0.y >= start.y && p0.y <= end.y) || (p0.y <= start.y && p0.y >= end.y) || (start.y == end.y)) && \
	((p0.z >= start.z && p0.z <= end.z) || (p0.z <= start.z && p0.z >= end.z) || (start.z == end.z)))
		return (true);
	if (((p1.x >= start.x && p1.x <= end.x) || (p1.x <= start.x && p1.x >= end.x) || (start.x == end.x)) && \
	((p1.y >= start.y && p1.y <= end.y) || (p1.y <= start.y && p1.y >= end.y) || (start.y == end.y)) && \
 	((p1.z >= start.z && p1.z <= end.z) || (p1.z <= start.z && p1.z >= end.z) || (start.z == end.z)))
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