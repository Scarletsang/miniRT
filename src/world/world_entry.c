/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:27:46 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 12:25:20 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include <stdlib.h>
#include <stdio.h>

bool	mrt_world_entry_is_empty(struct s_mrt_world_entry *entry)
{
	if (entry->identifier == ENTRY_SPHERE)
		return (entry->object.sphere == NULL);
	else if (entry->identifier == ENTRY_PLANE)
		return (entry->object.plane == NULL);
	else if (entry->identifier == ENTRY_CYLINDER)
		return (entry->object.cylinder == NULL);
	else if (entry->identifier == ENTRY_LIGHT_AMBIENT)
		return (entry->object.light_ambient == NULL);
	else if (entry->identifier == ENTRY_LIGHT_POINT)
		return (entry->object.light_point == NULL);
	else if (entry->identifier == ENTRY_CAMERA)
		return (entry->object.camera == NULL);
	else
		return (true);
}

/**
 * TODO: Replace free on each type of world entry to its corresponding free
 * function.
*/
void	mrt_world_entry_free(struct s_mrt_world_entry *entry)
{
	if (mrt_world_entry_is_empty(entry))
		return ;
	if (entry->identifier == ENTRY_SPHERE)
		mrt_sphere_free(entry->object.sphere);
	else if (entry->identifier == ENTRY_PLANE)
		mrt_plane_free(entry->object.plane);
	else if (entry->identifier == ENTRY_CYLINDER)
		mrt_cylinder_free(entry->object.cylinder);
	else if (entry->identifier == ENTRY_LIGHT_AMBIENT)
		free(entry->object.address);
	else if (entry->identifier == ENTRY_LIGHT_POINT)
		free(entry->object.address);
	else if (entry->identifier == ENTRY_CAMERA)
		mrt_camera_free(entry->object.camera);
	else
		free(entry->object.address);
}

void	mrt_world_entries_free(t_mrt_world_entries *entries)
{
	t_ft_vector_iterator	it;

	ft_vector_iterator_begin(&it, entries);
	while (!it.is_end)
	{
		mrt_world_entry_free(ft_vector_iterator_current(&it));
		ft_vector_iterator_next(&it);
	}
	ft_vector_free(entries);
}
