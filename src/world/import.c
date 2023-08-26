/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:16:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 19:58:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include "MINIRT/world/camera.h"
#include "MINIRT/world/game_object.h"
#include "MINIRT/world/light.h"
#include <stdlib.h>

static union u_world_entry_object	mrt_world_entry_object_from_scene_entry(\
struct s_mrt_scene_entry *scene_entry, struct s_mrt_world_options *options)
{
	union u_world_entry_object	object;

	if (scene_entry->identifier == ENTRY_SPHERE)
		object.sphere = mrt_sphere(scene_entry->object.sphere);
	else if (scene_entry->identifier == ENTRY_PLANE)
		object.plane = mrt_plane(scene_entry->object.plane);
	else if (scene_entry->identifier == ENTRY_CYLINDER)
		object.cylinder = mrt_cylinder(scene_entry->object.cylinder);
	else if (scene_entry->identifier == ENTRY_LIGHT_AMBIENT)
		object.light_ambient = mrt_light_ambient(\
			scene_entry->object.light_ambient);
	else if (scene_entry->identifier == ENTRY_LIGHT_POINT)
		object.light_point = mrt_light_point(scene_entry->object.light_point);
	else if (scene_entry->identifier == ENTRY_CAMERA)
		object.camera = mrt_camera(scene_entry->object.camera, \
			options->camera_image, options->camera_focal_length);
	else
		object = (union u_world_entry_object){};
	return (object);
}

static struct s_mrt_world_entry	mrt_world_entry_from_scene_entry(\
struct s_mrt_scene_entry *scene_entry, struct s_mrt_world_options *options)
{
	return ((struct s_mrt_world_entry){
		.identifier = scene_entry->identifier,
		.object = mrt_world_entry_object_from_scene_entry(scene_entry, options)
	});
}

static int	mrt_world_entry_add(struct s_mrt_world *world, \
struct s_mrt_world_entry world_entry)
{
	if (mrt_world_entry_is_empty(&world_entry))
	{
		mrt_world_free(world);
		return (EXIT_FAILURE);
	}
	else if (world_entry.identifier == ENTRY_LIGHT_AMBIENT || \
		world_entry.identifier == ENTRY_LIGHT_POINT)
	{
		if (ft_vector_append(&world->lights, &world_entry) == NULL)
		{
			mrt_world_free(world);
			return (EXIT_FAILURE);
		}
	}
	else if (world_entry.identifier == ENTRY_CAMERA)
		world->camera = world_entry;
	else
	{
		if (ft_vector_append(&world->objects, &world_entry) == NULL)
		{
			mrt_world_free(world);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	mrt_world_from_scene(struct s_mrt_scene *scene, struct s_mrt_world *world, \
struct s_mrt_world_options options)
{
	struct s_mrt_world_entry	world_entry;
	t_ft_vector_iterator		iterator;

	mrt_scene_print(scene);
	ft_vector_iterator_begin(&iterator, &scene->entries);
	while (!iterator.is_end)
	{
		world_entry = mrt_world_entry_from_scene_entry(\
			(struct s_mrt_scene_entry *) ft_vector_iterator_current(&iterator), \
			&options);
		if (mrt_world_entry_add(world, world_entry) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ft_vector_iterator_next(&iterator);
	}
	return (EXIT_SUCCESS);
}
