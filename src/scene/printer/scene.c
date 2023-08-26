/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:52:38 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 18:59:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include "MINIRT/scene/s_objects.h"
#include <stdio.h>

void	mrt_scene_print(struct s_mrt_scene *scene)
{
	t_ft_vector_iterator		iterator;
	struct s_mrt_scene_entry	*entry;

	ft_vector_iterator_begin(&iterator, &scene->entries);
	while (!iterator.is_end)
	{
		entry = ft_vector_iterator_current(&iterator);
		if (entry->identifier == ENTRY_CAMERA)
			mrt_scene_camera_print(entry->object.camera);
		else if (entry->identifier == ENTRY_LIGHT_AMBIENT)
			mrt_scene_light_ambient_print(entry->object.light_ambient);
		else if (entry->identifier == ENTRY_LIGHT_POINT)
			mrt_scene_light_point_print(entry->object.light_point);
		else if (entry->identifier == ENTRY_SPHERE)
			mrt_scene_sphere_print(entry->object.sphere);
		else if (entry->identifier == ENTRY_PLANE)
			mrt_scene_plane_print(entry->object.plane);
		else if (entry->identifier == ENTRY_CYLINDER)
			mrt_scene_cylinder_print(entry->object.cylinder);
		else
			printf("Unknown entry identifier: %d\n", entry->identifier);
		printf("\n");
		ft_vector_iterator_next(&iterator);
	}
}
