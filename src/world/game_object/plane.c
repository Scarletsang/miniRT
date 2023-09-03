/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/03 03:29:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include "MINIRT/renderer/ray.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

struct s_mrt_plane	*mrt_plane(struct s_mrt_scene_plane *scene_plane)
{
	struct s_mrt_plane	*pln;

	pln = malloc(sizeof(struct s_mrt_plane));
	if (!pln)
		return (NULL);
	scene_plane->normal = vec3_normalize(scene_plane->normal);
	*pln = (struct s_mrt_plane){.scene = scene_plane};
	return (pln);
}

/*
Formula to determine t (the t in the ray formula):
t = (plane->point - ray->origin) . plane->normal / ray->direction . plane->normal
*/

bool	mrt_plane_is_hit(struct s_mrt_ray *ray, struct s_mrt_plane *plane)
{
	t_mrt_vec3	tmp;
	double		t;
	double		distance;

	tmp = vec3_subtract(plane->scene->point, ray->origin);
	t = vec3_dot(ray->direction, plane->scene->normal);
	if (t == 0)
		return (false);
	t = vec3_dot(tmp, vec3_sdivide(plane->scene->normal, t));
	distance = vec3_length(vec3_smultiply(ray->direction, t));
	if (distance == 0)
		return (false);
	if (t < 0)
		return (false);
	return (true);
}

void	mrt_plane_free(struct s_mrt_plane *plane)
{
	free(plane->scene);
}

/*
Paper bin:

This was in mrt_plane_is_hit.
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
*/