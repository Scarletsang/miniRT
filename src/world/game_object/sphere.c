/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:23 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 22:33:35 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include "MINIRT/scene.h"
#include <stdlib.h>
#include <math.h>

struct s_mrt_sphere	*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere)
{
	struct s_mrt_sphere	*sph;

	sph = malloc(sizeof(struct s_mrt_sphere));
	if (!sph)
		return (NULL);
	*sph = (struct s_mrt_sphere){.scene = scene_sphere};
	return (sph);
}

void	mrt_sphere_free(struct s_mrt_sphere *sphere)
{
	free(sphere->scene);
}
