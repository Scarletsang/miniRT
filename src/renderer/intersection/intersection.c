/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 10:50:52 by htsang            #+#    #+#             */
/*   Updated: 2023/09/05 13:51:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/renderer/intersection.h"

inline struct s_mrt_intersection	mrt_intersection(double time, \
struct s_mrt_world_entry object)
{
	return ((struct s_mrt_intersection){
		.time = time,
		.object = object
	});
}

inline bool	mrt_intersection_is_empty(\
struct s_mrt_intersection *intersection)
{
	return (mrt_world_entry_is_empty(&intersection->object));
}

inline struct s_mrt_intersection	mrt_intersection_empty(void)
{
	return (mrt_intersection(0, (struct s_mrt_world_entry){\
		.identifier = ENTRY_UNKNOWN, \
		.object = (union u_world_entry_object){.address = NULL} \
	}));
}

struct s_mrt_intersection	mrt_intersect_object(\
struct s_mrt_world_entry object, struct s_mrt_ray *ray)
{
	if (object.identifier == ENTRY_SPHERE)
		return (mrt_intersection(mrt_intersect_sphere(\
			object.object.sphere, ray), object));
	else if (object.identifier == ENTRY_PLANE)
		return (mrt_intersection(mrt_intersect_plane(\
			object.object.plane, ray), object));
	else if (object.identifier == ENTRY_CYLINDER)
		return (mrt_intersection(mrt_intersect_cylinder(\
			object.object.cylinder, ray), object));
	else
		return (mrt_intersection_empty());
}

struct s_mrt_intersection	mrt_intersect_world(\
struct s_mrt_renderer_data *renderer, t_mrt_ray ray)
{
	t_ft_vector_iterator		iterator;
	struct s_mrt_intersection	*intersection;

	ft_vector_iterator_begin(&iterator, &renderer->world->objects);
	while (!iterator.is_end)
	{
		intersection = mrt_allocate_intersection(\
			&renderer->cache.allocators);
		if (intersection == NULL)
			return (mrt_intersection_empty());
		*intersection = mrt_intersect_object(*(struct s_mrt_world_entry *) \
			ft_vector_iterator_current(&iterator), &ray);
		if (mrt_intersection_is_empty(intersection))
			mrt_free(&renderer->cache.allocators.intersections, intersection);
		else if (mrt_intersections_add(\
			&renderer->cache.intersections, intersection))
			return (mrt_intersection_empty());
		ft_vector_iterator_next(&iterator);
	}
	mrt_intersections_sort(&renderer->cache.intersections);
	return (mrt_intersections_nearest(&renderer->cache.intersections));
}
