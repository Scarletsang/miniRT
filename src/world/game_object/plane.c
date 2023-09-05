/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:57 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 22:45:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include "MINIRT/unit.h"
#include <stdlib.h>

struct s_mrt_plane	*mrt_plane(struct s_mrt_scene_plane *scene_plane)
{
	struct s_mrt_plane	*pln;

	pln = malloc(sizeof(struct s_mrt_plane));
	if (!pln)
		return (NULL);
	scene_plane->normal = vec3_normalize(scene_plane->normal);
	*pln = (struct s_mrt_plane){.scene = scene_plane};
	return (pln);
}

void	mrt_plane_free(struct s_mrt_plane *plane)
{
	free(plane->scene);
}
