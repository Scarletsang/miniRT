/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:31:59 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 06:13:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene/s_objects.h"

void	mrt_material_default(struct s_mrt_material *material)
{
	*material = (struct s_mrt_material){
		.color = vec3(0.0, 0.0, 0.0),
		.diffuse = 0.9,
		.specular = 0.9,
		.shininess = 100.0
	};
}
