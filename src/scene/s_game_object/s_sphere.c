/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_sphere.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:08:02 by kisikogl          #+#    #+#             */
/*   Updated: 2023/08/14 15:44:52 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"
#include "MINIRT/scene/s_game_object.h"
#include "MINIRT/unit.h"
#include <stdlib.h>

struct s_mrt_scene_entry	mrt_scene_sphere( \
t_mrt_point3d center, double diameter, t_mrt_color color)
{
	struct s_mrt_scene_entry	entry_sph;
	union u_scene_entry_object	object;

	entry_sph.identifier = ENTRY_SPHERE;
	object.sphere = malloc(sizeof(struct s_mrt_scene_sphere));
	if (!object.sphere)
	{
		entry_sph.object = mrt_scene_entry_object_empty();
		return (entry_sph);
	}
	*object.sphere = (struct s_mrt_scene_sphere){
		.center = center,
		.diameter = diameter,
		.color = color};
	entry_sph.object = object;
	return (entry_sph);
}
