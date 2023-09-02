/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/01 16:25:47 by htsang           ###   ########.fr       */
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

static void	mrt_scene_unique_identifier_copier(\
enum e_mrt_scene_entry_identifier *dest, enum e_mrt_scene_entry_identifier *src)
{
	*dest = *src;
}

int	mrt_scene_init(struct s_mrt_scene *scene)
{
	if (ft_vector_init(&scene->entries, sizeof(struct s_mrt_scene_entry), \
		8, (t_ft_vector_item_copier) mrt_scene_entries_copier))
		return (EXIT_FAILURE);
	if (ft_vector_init(&scene->unique_identifiers, \
		sizeof(enum e_mrt_scene_entry_identifier), \
		3, (t_ft_vector_item_copier) mrt_scene_unique_identifier_copier))
	{
		ft_vector_free(&scene->entries);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	mrt_scene_free(struct s_mrt_scene *scene)
{
	ft_vector_free(&scene->entries);
	ft_vector_free(&scene->unique_identifiers);
}

int	mrt_scene_add_entry(struct s_mrt_scene *scene, \
struct s_mrt_scene_entry entry, bool is_unique)
{
	if (entry.object.camera == NULL)
		return (EXIT_FAILURE);
	if (is_unique || (entry.identifier == ENTRY_CAMERA) || \
		(entry.identifier == ENTRY_LIGHT_AMBIENT))
	{
		if (mrt_scene_has_unique_identifier(scene, entry.identifier))
			return (EXIT_FAILURE);
	}
	mrt_scene_add_unique_identifier(scene, entry.identifier);
	if (!ft_vector_append(&scene->entries, &entry))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
