/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:08:48 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 04:33:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "MINIRT/unit.h"
# include "MINIRT/world.h"
# include "MINIRT/image.h"

struct	s_mrt_world;

typedef struct s_mrt_ray
{
	t_mrt_point3d			origin;
	t_mrt_direction3d		direction;
	t_mrt_direction3d_unit	direction_unit;
}				t_mrt_ray;

t_mrt_ray					mrt_ray_omit_unit(t_mrt_point3d origin, \
t_mrt_direction3d direction);

t_mrt_ray					mrt_ray(t_mrt_point3d origin, \
t_mrt_direction3d direction);

t_mrt_point3d				ray_at(t_mrt_ray *ray, double t);

#endif