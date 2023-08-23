/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:41 by htsang            #+#    #+#             */
/*   Updated: 2023/08/23 14:21:16 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/ray.h"
#include "MINIRT/unit.h"
#include <stdlib.h>
#include <stdbool.h>

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_cylinder)
{
	struct s_mrt_cylinder	*cyl;

	cyl = malloc(sizeof(struct s_mrt_cylinder));
	if (!cyl)
		return (NULL);
	*cyl = (struct s_mrt_cylinder){.scene = scene_cylinder};
	return (cyl);
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

bool	mrt_cylinder_is_hit(struct s_mrt_ray *ray \
	, struct s_mrt_cylinder *cylinder)
{
	t_mrt_vec3	x;
	double		r;
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		tmp;

	x = vec3_subtract(ray->origin, cylinder->scene->center);
	r = cylinder->scene->dia_height.x / 2;
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	tmp = tmp * tmp;
	a = vec3_dot(ray->direction, ray->direction) - tmp;
	tmp = vec3_dot(ray->direction, cylinder->scene->orientation);
	tmp = tmp * vec3_dot(x, cylinder->scene->orientation);
	b = (vec3_dot(ray->direction, x) - tmp) * 2;
	tmp = vec3_dot(x, cylinder->scene->orientation);
	c = vec3_dot(x, x) - tmp * tmp - r * r;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	return (true);
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