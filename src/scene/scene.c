/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:55:02 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 06:56:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include "MINIRT/error.h"
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

bool	mrt_scene_is_valid(struct s_mrt_scene *scene)
{
	bool					has_camera;
	bool					has_ambient;
	t_ft_vector_iterator	it;

	has_camera = false;
	has_ambient = false;
	ft_vector_iterator_begin(&it, &scene->unique_identifiers);
	while (!it.is_end)
	{
		if (*((enum e_mrt_scene_entry_identifier *) \
			ft_vector_iterator_current(&it)) == ENTRY_CAMERA)
			has_camera = true;
		else if (*((enum e_mrt_scene_entry_identifier *) \
			ft_vector_iterator_current(&it)) == ENTRY_LIGHT_AMBIENT)
			has_ambient = true;
		ft_vector_iterator_next(&it);
	}
	if (!has_camera)
		mrt_error_printer(MRT_ERROR_WORLD_MISSING_CAMERA);
	if (!has_ambient)
		mrt_error_printer(MRT_ERROR_WORLD_MISSING_AMBIENT_LIGHT);
	return (has_camera && has_ambient);
}
