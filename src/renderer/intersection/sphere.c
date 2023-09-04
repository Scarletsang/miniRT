/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:59:10 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 20:54:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/unit.h"
#include <math.h>

double	mrt_intersect_sphere(struct s_mrt_sphere *sphere, struct s_mrt_ray *ray)
{
	t_mrt_direction3d	sph_to_ray;
	t_mrt_vec3			quadratic;
	double				radius;
	double				discriminant;

	sph_to_ray = vec3_subtract(ray->origin, sphere->scene->center);
	radius = sphere->scene->diameter / 2;
	quadratic = (t_mrt_vec3){
		.x = vec3_dot(ray->direction, ray->direction), \
		.y = vec3_dot(vec3_smultiply(ray->direction, 2.0), sph_to_ray), \
		.z = vec3_dot(sph_to_ray, sph_to_ray) - radius * radius
	};
	discriminant = quadratic.y * quadratic.y - 4 * quadratic.x * quadratic.z;
	if (discriminant < 0)
		return (-1);
	return ((-quadratic.y - sqrt(discriminant)) / (2.0 * quadratic.x));
}