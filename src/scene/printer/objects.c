/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:41:34 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 18:48:20 by htsang           ###   ########.fr       */
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
	printf("    origin      : ");
	vec3_print(plane->origin);
	printf("    orientation : ");
	vec3_print(plane->orientation);
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
