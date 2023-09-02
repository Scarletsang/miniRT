/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:41:34 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 15:25:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_objects.h"
#include <stdio.h>

void	mrt_material_print(struct s_mrt_material *material)
{
	printf("    color       : ");
	vec3_print(material->color);
	printf("    diffuse     : %f\n", material->diffuse);
	printf("    specular    : %f\n", material->specular);
	printf("    shininess   : %f\n", material->shininess);
}

void	mrt_scene_sphere_print(struct s_mrt_scene_sphere *sphere)
{
	printf("sphere:\n");
	printf("    center      : ");
	vec3_print(sphere->center);
	printf("    diameter    : %f\n", sphere->diameter);
	mrt_material_print(&sphere->material);
}

void	mrt_scene_plane_print(struct s_mrt_scene_plane *plane)
{
	printf("plane:\n");
	printf("    point       : ");
	vec3_print(plane->point);
	printf("    normal      : ");
	vec3_print(plane->normal);
	mrt_material_print(&plane->material);
}

void	mrt_scene_cylinder_print(struct s_mrt_scene_cylinder *cylinder)
{
	printf("cylinder:\n");
	printf("    center      : ");
	vec3_print(cylinder->center);
	printf("    orientation : ");
	vec3_print(cylinder->orientation);
	printf("    height      : %f\n", cylinder->height);
	printf("    diameter    : %f\n", cylinder->diameter);
	mrt_material_print(&cylinder->material);
}
