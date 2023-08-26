/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:57 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:17:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene/s_objects.h"
#include <stdlib.h>

struct s_mrt_plane	*mrt_plane(struct s_mrt_scene_plane *scene_plane)
{
	struct s_mrt_plane	*plane;

	plane = malloc(sizeof(struct s_mrt_plane));
	if (!plane)
		return (NULL);
	*plane = (struct s_mrt_plane){
		.scene = scene_plane
	};
	return (plane);
}

bool	mrt_plane_is_hit(struct s_mrt_ray *ray, struct s_mrt_plane *plane)
{
	(void) ray;
	(void) plane;
	return (false);
}
