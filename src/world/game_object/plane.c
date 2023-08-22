/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:57 by htsang            #+#    #+#             */
/*   Updated: 2023/08/22 12:18:09 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include <stdlib.h>

struct s_mrt_plane	*mrt_plane(struct s_mrt_scene_plane *scene_plane)
{
	struct s_mrt_plane	*pln;

	pln = malloc(sizeof(struct s_mrt_plane));
	if (!pln)
		return (NULL);
	*pln = (struct s_mrt_plane){.scene = scene_plane};
	return (pln);
}

bool	mrt_plane_is_hit(struct s_mrt_ray *ray, struct s_mrt_plane *plane)
{
	(void) ray;
	(void) plane;
	return (false);
}