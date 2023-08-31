/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:41:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 12:31:42 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_objects.h"
#include <stdio.h>

void	mrt_scene_sphere_print(struct s_mrt_scene_sphere *sphere)
{
	printf("sphere:\n");
	printf("    center      : ");
	vec3_print(sphere->center);
	printf("    diameter    : %f\n", sphere->diameter);
	printf("    color       : ");
	vec3_print(sphere->color);
}

void	mrt_scene_plane_print(struct s_mrt_scene_plane *plane)
{
	printf("plane:\n");
	printf("    point      : ");
	vec3_print(plane->point);
	printf("    normal     : ");
	vec3_print(plane->normal);
	printf("    color       : ");
	vec3_print(plane->color);
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
	printf("    color       : ");
	vec3_print(cylinder->color);
}
