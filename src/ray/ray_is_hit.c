/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_is_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:47 by kisikogl          #+#    #+#             */
/*   Updated: 2023/08/26 20:19:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/ray.h"
#include "MINIRT/world.h"

/**
 * TODO: Change this function to make it detect it the
 * nearest one.
*/
int	mrt_ray_is_hit(t_mrt_ray *ray, struct s_mrt_world *world)
{
	struct s_mrt_world_entry	*entry;
	size_t						i;

	i = 0;
	while (i < world->objects.size)
	{
		entry = (struct s_mrt_world_entry *)ft_vector_get(&world->objects, i);
		if (entry->identifier == ENTRY_SPHERE)
			if (mrt_sphere_is_hit(ray, entry->object.sphere))
				return (ENTRY_SPHERE);
		if (entry->identifier == ENTRY_PLANE)
			if (mrt_plane_is_hit(ray, entry->object.plane))
				return (ENTRY_PLANE);
		if (entry->identifier == ENTRY_CYLINDER)
			if (mrt_cylinder_is_hit(ray, entry->object.cylinder))
				return (ENTRY_CYLINDER);
		i++;
	}
	return (ENTRY_ZERO);
}
