/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:23 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 15:25:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include "MINIRT/ray.h"
#include <stdbool.h>
#include <stdlib.h>

struct s_mrt_sphere	*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere)
{
	struct s_mrt_sphere	*sph;

	sph = malloc(sizeof(struct s_mrt_sphere));
	if (!sph)
		return (NULL);
	*sph = (struct s_mrt_sphere){.scene = scene_sphere};
	return (sph);
}

bool	mrt_sphere_is_hit(struct s_mrt_ray *ray, struct s_mrt_sphere *sphere)
{
	t_mrt_direction3d	sph_to_ray;
	double				radius;
	t_mrt_vec3			quadratic;

	sph_to_ray = vec3_subtract(ray->origin, sphere->scene->center);
	radius = sphere->scene->diameter / 2;
	quadratic = (t_mrt_vec3){
		.x = vec3_dot(ray->direction, ray->direction), \
		.y = vec3_dot(vec3_smultiply(ray->direction, 2.0), sph_to_ray), \
		.z = vec3_dot(sph_to_ray, sph_to_ray) - radius * radius
	};
	return ((quadratic.y * quadratic.y - 4 * quadratic.x * quadratic.z) >= 0);
}

void	mrt_sphere_free(struct s_mrt_sphere *sphere)
{
	free(sphere->scene);
}
