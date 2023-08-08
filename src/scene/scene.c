/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 12:46:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include <stdlib.h>
#include <stdbool.h>

static void	mrt_scene_entries_copier(struct s_mrt_scene_entry *dest, \
	struct s_mrt_scene_entry *src)
{
	*dest = *src;
}

int	mrt_scene_init(struct s_mrt_scene *scene)
{
	if (ft_vector_init(&scene->entries, sizeof(struct s_mrt_scene_entry), \
		8, (t_ft_vector_item_copier) mrt_scene_entries_copier))
		return (EXIT_FAILURE);
	scene->camera_count = 0;
	scene->light_count = 0;
	return (EXIT_SUCCESS);
}

void	mrt_scene_free(struct s_mrt_scene *scene)
{
	ft_vector_free(&scene->entries);
	scene->camera_count = 0;
	scene->light_count = 0;
}

int	mrt_scene_add_entry(struct s_mrt_scene *scene, \
	struct s_mrt_scene_entry entry)
{
	if (entry.identifier == ENTRY_CAMERA)
		scene->camera_count++;
	else if (entry.identifier == ENTRY_LIGHT_AMBIENT || \
		entry.identifier == ENTRY_LIGHT_POINT)
		scene->light_count++;
	if (scene->camera_count > 1)
		return (EXIT_FAILURE);
	if (!ft_vector_append(&scene->entries, &entry))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
