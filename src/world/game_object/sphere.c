/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 19:22:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene/s_objects.h"
#include <stdlib.h>

struct s_mrt_sphere	*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere)
{
	struct s_mrt_sphere	*sphere;

	sphere = malloc(sizeof(struct s_mrt_sphere));
	if (!sphere)
		return (NULL);
	*sphere = (struct s_mrt_sphere){
		.scene = scene_sphere
	};
	return (sphere);
}
