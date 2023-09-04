/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_is_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:00:47 by kisikogl          #+#    #+#             */
/*   Updated: 2023/09/04 14:21:37 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/ray.h"
#include "MINIRT/world.h"
#include <stdbool.h>

struct s_mrt_world_insec	get_nearest(t_mrt_ray *ray, struct \
s_mrt_world_insec insec, t_mrt_t1t2 t1t2, struct s_mrt_world_entry *entry)
{
	double	t;
	double	distance;
	double	tmp;

	distance = ray_distance(ray, t1t2.x);
	t = t1t2.x;
	tmp = ray_distance(ray, t1t2.y);
	if (tmp < distance)
	{
		distance = tmp;
		t = t1t2.y;
	}
	if (insec.entry != NULL)
	{
		if (ray_distance(ray, insec.t) <= distance)
			return (insec);
	}
	insec.t = t;
	insec.entry = entry;
	return (insec);
}

bool	get_t_factor(struct s_mrt_world_entry *entry, t_mrt_ray *ray, \
t_mrt_t1t2 *t1t2)
{
	if (entry == NULL)
		return (false);
	if (entry->identifier == ENTRY_SPHERE)
	{
		if (mrt_sphere_is_hit(ray, entry->object.sphere, t1t2))
			return (true);
	}
	else if (entry->identifier == ENTRY_CYLINDER)
	{
		if (mrt_cylinder_is_hit(ray, entry->object.cylinder, t1t2))
			return (true);
	}
	else if (entry->identifier == ENTRY_PLANE)
	{
		if (mrt_plane_is_hit(ray, entry->object.plane, t1t2))
			return (true);
	}
	return (false);
}

struct s_mrt_world_insec	mrt_ray_is_hit(t_mrt_ray *ray \
, struct s_mrt_world *world)
{
	struct s_mrt_world_entry	*entry;
	struct s_mrt_world_insec	insec;
	t_mrt_t1t2					t1t2;
	size_t						i;

	i = 0;
	insec.entry = NULL;
	while (i < world->objects.size)
	{
		entry = (struct s_mrt_world_entry *)ft_vector_get(&world->objects, i);
		if (get_t_factor(entry, ray, &t1t2))
			insec = get_nearest(ray, insec, t1t2, entry);
		i++;
	}
	return (insec);
}
