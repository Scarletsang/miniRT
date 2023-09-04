/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:53:44 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 21:50:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include "MINIRT/scene/s_objects.h"
#include "LIBFT/string.h"
#include <stdlib.h>

static void	*mrt_scene_entry_allocate(\
enum e_mrt_scene_entry_identifier identifier, size_t *size)
{
	if (identifier == ENTRY_SPHERE)
		*size = sizeof(struct s_mrt_scene_sphere);
	else if (identifier == ENTRY_PLANE)
		*size = sizeof(struct s_mrt_scene_plane);
	else if (identifier == ENTRY_CYLINDER)
		*size = sizeof(struct s_mrt_scene_cylinder);
	else if (identifier == ENTRY_LIGHT_AMBIENT)
		*size = sizeof(struct s_mrt_scene_light_ambient);
	else if (identifier == ENTRY_LIGHT_POINT)
		*size = sizeof(struct s_mrt_scene_light_point);
	else if (identifier == ENTRY_CAMERA)
		*size = sizeof(struct s_mrt_scene_camera);
	else
		return (NULL);
	return (malloc(*size));
}

struct s_mrt_scene_entry	mrt_scene_entry(void *scene_object, \
enum e_mrt_scene_entry_identifier identifier)
{
	union u_scene_entry_object	object;
	size_t						size;

	object.camera = mrt_scene_entry_allocate(identifier, &size);
	if (!object.camera)
		return ((struct s_mrt_scene_entry){
			.identifier = identifier,
			.object = mrt_scene_entry_object_empty()
		});
	ft_memmove(object.camera, scene_object, size);
	return ((struct s_mrt_scene_entry){
		.identifier = identifier,
		.object = object
	});
}

union u_scene_entry_object	mrt_scene_entry_object_empty(void)
{
	return ((union u_scene_entry_object){.camera = NULL});
}

bool	mrt_scene_entry_object_is_empty(union u_scene_entry_object entry_object)
{
	return (entry_object.camera == NULL);
}

int	mrt_scene_add_entry(struct s_mrt_scene *scene, \
struct s_mrt_scene_entry entry, bool is_unique)
{
	if (entry.object.camera == NULL)
		return (EXIT_FAILURE);
	if (is_unique || (entry.identifier == ENTRY_CAMERA))
	{
		if (mrt_scene_has_unique_identifier(scene, entry.identifier))
			return (EXIT_FAILURE);
	}
	mrt_scene_add_unique_identifier(scene, entry.identifier);
	if (!ft_vector_append(&scene->entries, &entry))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
