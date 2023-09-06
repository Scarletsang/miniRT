/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:41 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 05:33:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include <stdlib.h>

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_cylinder)
{
	struct s_mrt_cylinder	*cyl;

	cyl = malloc(sizeof(struct s_mrt_cylinder));
	if (!cyl)
		return (NULL);
	scene_cylinder->orientation = vec3_normalize(scene_cylinder->orientation);
	*cyl = (struct s_mrt_cylinder){.scene = scene_cylinder};
	mrt_cylinder_refresh(cyl);
	return (cyl);
}

void	mrt_cylinder_refresh(struct s_mrt_cylinder *cylinder)
{
	cylinder->color = mrt_color_to_color_unit(cylinder->scene->material.color);
}

void	mrt_cylinder_free(struct s_mrt_cylinder *cylinder)
{
	free(cylinder->scene);
}
