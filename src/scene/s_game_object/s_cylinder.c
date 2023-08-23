/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cylinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:33:32 by kisikogl          #+#    #+#             */
/*   Updated: 2023/08/23 10:40:59 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include <stdlib.h>

struct s_mrt_scene_entry	mrt_scene_cylinder(t_mrt_point3d center, \
t_mrt_vec3_unit orientation, t_mrt_dimension dia_height, t_mrt_color color)
{
	struct s_mrt_scene_entry	entry_cyl;
	union u_scene_entry_object	object;

	entry_cyl.identifier = ENTRY_CYLINDER;
	object.cylinder = malloc(sizeof(struct s_mrt_scene_cylinder));
	if (!object.cylinder)
	{
		entry_cyl.object = mrt_scene_entry_object_empty();
		return (entry_cyl);
	}
	*object.cylinder = (struct s_mrt_scene_cylinder){
		.center = center,
		.orientation = orientation,
		.dia_height = dia_height,
		.color = color};
	entry_cyl.object = object;
	return (entry_cyl);
}
