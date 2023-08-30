/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:57 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 16:11:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include "MINIRT/ray.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
	t = vec3_dot(tmp, vec3_divide(plane->scene->normal, t));
	if (t < 0)
		return (false);
	distance = vec3_length(vec3_multiply(ray->direction, t));
	(void) distance;
	return (true);
}

void	mrt_plane_free(struct s_mrt_plane *plane)
{
	free(plane->scene);
}
