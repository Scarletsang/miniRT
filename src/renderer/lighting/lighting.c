/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:44:50 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 13:27:13 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/lighting.h"

static void	mrt_lighting_prepare_sphere( \
struct s_mrt_lighting *lighting_data, struct s_mrt_sphere *sphere, \
struct s_mrt_light_ambient *ambient_light, t_mrt_ray *ray)
{
	lighting_data->normal = mrt_lighting_normal_at_sphere(\
		sphere, lighting_data->hit_position);
	lighting_data->material = sphere->scene->material;
	if (mrt_lighting_is_camera_inside_sphere(sphere, ray))
		lighting_data->material.color = vec3_return_zero();
	else
		lighting_data->material.color = vec3_multiply(\
			sphere->color, ambient_light->color);
}

static void	mrt_lighting_prepare_cylinder( \
struct s_mrt_lighting *lighting_data, struct s_mrt_cylinder *cylinder, \
struct s_mrt_light_ambient *ambient_light, t_mrt_ray *ray)
{
	lighting_data->normal = mrt_lighting_normal_at_cylinder(\
		cylinder, lighting_data->hit_position);
	lighting_data->material = cylinder->scene->material;
	if (mrt_lighting_is_camera_inside_cylinder(cylinder, ray))
		lighting_data->material.color = vec3_return_zero();
	else
		lighting_data->material.color = vec3_multiply(\
			cylinder->color, ambient_light->color);
}

static void	mrt_lighting_prepare_plane(struct s_mrt_lighting *lighting_data, \
struct s_mrt_plane *plane, struct s_mrt_light_ambient *ambient_light)
{
	lighting_data->normal = mrt_lighting_normal_at_plane(\
		plane, lighting_data->hit_position);
	lighting_data->material = plane->scene->material;
	lighting_data->material.color = vec3_multiply(\
		plane->color, ambient_light->color);
}

static void	mrt_lighting_prepare_failure(struct s_mrt_lighting *lighting_data)
{
	lighting_data->normal = vec3(0, 0, 0);
	lighting_data->material = (struct s_mrt_material){0};
	lighting_data->material.color = vec3(0, 0, 0);
}

void	mrt_lighting_prepare(struct s_mrt_lighting *lighting_data, \
t_mrt_ray *ray, struct s_mrt_intersection intersection, \
struct s_mrt_light_ambient *ambient_light)
{
	lighting_data->eye_vector = vec3_negate(ray->direction_unit);
	lighting_data->hit_position = ray_at(ray, intersection.time);
	lighting_data->ambient_effectiveness = ambient_light->scene->ratio;
	if (intersection.object.identifier == ENTRY_SPHERE)
		mrt_lighting_prepare_sphere(lighting_data, \
			intersection.object.object.sphere, ambient_light, ray);
	else if (intersection.object.identifier == ENTRY_PLANE)
		mrt_lighting_prepare_plane(lighting_data, \
			intersection.object.object.plane, ambient_light);
	else if (intersection.object.identifier == ENTRY_CYLINDER)
		mrt_lighting_prepare_cylinder(lighting_data, \
			intersection.object.object.cylinder, ambient_light, ray);
	else
		mrt_lighting_prepare_failure(lighting_data);
}
