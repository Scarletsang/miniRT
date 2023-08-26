/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:41 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:17:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene/s_objects.h"
#include <stdlib.h>

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_cylinder)
{
	struct s_mrt_cylinder	*cylinder;

	cylinder = malloc(sizeof(struct s_mrt_cylinder));
	if (!cylinder)
		return (NULL);
	*cylinder = (struct s_mrt_cylinder){
		.scene = scene_cylinder
	};
	return (cylinder);
}

bool	mrt_cylinder_is_hit(struct s_mrt_ray *ray \
	, struct s_mrt_cylinder *cylinder)
{
	(void) ray;
	(void) cylinder;
	return (false);
}
