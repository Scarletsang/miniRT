/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:04:19 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 03:25:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/unit.h"
#include <math.h>
#include <stdbool.h>

/*
Formula to determine t (the t in the ray formula):
t = (plane->point - ray->origin) . plane->normal / ray->direction . plane->normal
*/

double	mrt_intersect_plane(struct s_mrt_plane *plane, struct s_mrt_ray *ray)
{
	t_mrt_vec3			tmp;
	double				t;

	tmp = vec3_subtract(plane->scene->point, ray->origin);
	t = vec3_dot(ray->direction, plane->scene->normal);
	if (t == 0)
		return (t);
	t = vec3_dot(tmp, vec3_sdivide(plane->scene->normal, t));
	return (t);
}

/*
Paper bin:

This was in mrt_intersect_plane.
This was to prevent rendering when the camera is looking straight
at the edge of the plane:

static void	*inrenderable = NULL;

if (plane == inrenderable)
	return (false);
if (fabs(t) < 0.1)
{
	inrenderable = plane;
	return (false);
}
Calculating the distance between the ray and the plane:

distance = vec3_length(vec3_smultiply(ray->direction, t));
*/
