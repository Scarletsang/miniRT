/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:15:35 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 19:21:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/light.h"
#include "MINIRT/scene/s_objects.h"
#include <stdlib.h>

struct s_mrt_light_point	*mrt_light_point(\
struct s_mrt_scene_light_point *scene_light_point)
{
	struct s_mrt_light_point	*light_point;

	light_point = malloc(sizeof(struct s_mrt_light_point));
	if (!light_point)
		return (NULL);
	*light_point = (struct s_mrt_light_point){
		.scene = scene_light_point
	};
	return (light_point);
}
