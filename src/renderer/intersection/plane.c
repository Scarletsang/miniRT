/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:04:19 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 07:53:40 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/unit.h"
#include <math.h>

/*
Formula to determine t (the t in the ray formula):
t = (plane->point - ray->origin) . plane->normal / ray->direction . plane->normal
*/

double	mrt_intersect_plane(struct s_mrt_plane *plane, struct s_mrt_ray *ray)
{
	t_mrt_vec3			ray_to_plane;
	double				t;

	ray_to_plane = vec3_subtract(plane->scene->point, ray->origin);
	t = vec3_dot(ray->direction, plane->scene->normal);
	t = vec3_dot(ray_to_plane, vec3_sdivide(plane->scene->normal, t));
	return (t);
}
