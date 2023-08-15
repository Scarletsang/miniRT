/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:17:41 by htsang            #+#    #+#             */
/*   Updated: 2023/08/15 14:24:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world/game_object.h"
#include <stdlib.h>

struct s_mrt_cylinder	*mrt_cylinder(struct s_mrt_scene_cylinder *scene_sphere)
{
	(void)scene_sphere;
	return (NULL);
}

bool	mrt_cylinder_is_hit(struct s_mrt_ray *ray \
	, struct s_mrt_cylinder *cylinder)
{
	(void) ray;
	(void) cylinder;
	return (false);
}