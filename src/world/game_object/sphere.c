/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/11 12:46:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/unit.h"
#include "MINIRT/ray.h"
#include <stdbool.h>
#include <stdlib.h>

struct s_mrt_sphere	*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere)
{
	(void)scene_sphere;
	return (NULL);
}

bool	mrt_sphere_is_hit(t_mrt_ray *ray, t_mrt_point3d center, double radius)
{
	t_mrt_direction3d	sph_to_ray;
	double				a;
	double				b;
	double				c;
	bool				is_hit;

	sph_to_ray = vec3_subtract(ray->origin, center);
	a = vec3_dot(ray->direction, ray->direction);
	b = vec3_dot(vec3_multiply(ray->direction, 2.0), sph_to_ray);
	c = vec3_dot(sph_to_ray, sph_to_ray) - radius * radius;
	is_hit = (b * b - 4 * a * c) >= 0;
	return (is_hit);
}