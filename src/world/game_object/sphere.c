/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/17 13:48:18 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
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
	double				a;
	double				b;
	double				c;
	bool				is_hit;

	sph_to_ray = vec3_subtract(ray->origin, sphere->scene->center);
	radius = sphere->scene->diameter / 2;
	a = vec3_dot(ray->direction, ray->direction);
	b = vec3_dot(vec3_multiply(ray->direction, 2.0), sph_to_ray);
	c = vec3_dot(sph_to_ray, sph_to_ray) - radius * radius;
	is_hit = (b * b - 4 * a * c) >= 0;
	return (is_hit);
}

void	mrt_sphere_free(struct s_mrt_sphere *sphere)
{
	free(sphere->scene);
}
