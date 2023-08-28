/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:16:30 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 19:38:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/light.h"
#include "MINIRT/scene/s_objects.h"
#include <stdlib.h>

struct s_mrt_light_ambient	*mrt_light_ambient(\
struct s_mrt_scene_light_ambient *scene_light_ambient)
{
	struct s_mrt_light_ambient	*light_ambient;

	light_ambient = malloc(sizeof(struct s_mrt_light_ambient));
	if (!light_ambient)
		return (NULL);
	*light_ambient = (struct s_mrt_light_ambient){
		.scene = scene_light_ambient
	};
	return (light_ambient);
}
