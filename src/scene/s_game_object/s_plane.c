/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_plane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:22:37 by kisikogl          #+#    #+#             */
/*   Updated: 2023/08/22 13:27:29 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include <stdlib.h>

struct s_mrt_scene_entry	mrt_scene_plane( \
t_mrt_point3d point, t_mrt_vec3_unit normal, t_mrt_color color)
{
	struct s_mrt_scene_entry	entry_pln;
	union u_scene_entry_object	object;

	entry_pln.identifier = ENTRY_PLANE;
	object.plane = malloc(sizeof(struct s_mrt_scene_plane));
	if (!object.plane)
	{
		entry_pln.object = mrt_scene_entry_object_empty();
		return (entry_pln);
	}
	*object.plane = (struct s_mrt_scene_plane){
		.point = point,
		.normal = normal,
		.color = color};
	entry_pln.object = object;
	return (entry_pln);
}
