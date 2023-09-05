/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:16:13 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 02:53:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include <stdlib.h>

static void	mrt_scene_entries_copier(struct s_mrt_world_entry *dest, \
	struct s_mrt_world_entry *src)
{
	*dest = *src;
}

int	mrt_world_init(struct s_mrt_world *world)
{
	if (ft_vector_init(&world->point_lights, \
		sizeof(struct s_mrt_world_entry), 8, (t_ft_vector_item_copier) \
			mrt_scene_entries_copier))
		return (EXIT_FAILURE);
	else if (ft_vector_init(&world->objects, \
		sizeof(struct s_mrt_world_entry), 8, (t_ft_vector_item_copier) \
			mrt_scene_entries_copier))
	{
		ft_vector_free(&world->point_lights);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	mrt_world_free(struct s_mrt_world *world)
{
	mrt_world_entries_free(&world->point_lights);
	mrt_world_entries_free(&world->objects);
	mrt_world_entry_free(&world->camera);
	mrt_world_entry_free(&world->ambient_light);
}

struct s_mrt_camera	*mrt_world_get_camera(struct s_mrt_world *world)
{
	return (world->camera.object.camera);
}

struct s_mrt_light_ambient	*mrt_world_get_ambient_light(\
struct s_mrt_world *world)
{
	return (world->ambient_light.object.light_ambient);
}
