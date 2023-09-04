/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:41 by htsang            #+#    #+#             */
/*   Updated: 2023/09/03 11:03:22 by htsang           ###   ########.fr       */
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
	return (cyl);
}

void	mrt_cylinder_free(struct s_mrt_cylinder *cylinder)
{
	free(cylinder->scene);
}
