/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:08:48 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 12:06:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include "unit.h"
#include "camera.h"
#include "image.h"

typedef struct s_mrt_ray
{
	t_mrt_point3d		orig;
	t_mrt_direction3d	dir;
}				t_mrt_ray;

t_mrt_ray		*ray_create(t_mrt_point3d origin, t_mrt_direction3d direction);
t_mrt_color		ray_color(t_mrt_ray	*ray);
t_mrt_point3d	ray_at(t_mrt_ray *ray, double t);
void			ray_ppm(void);
void			ray_ppm_loop(struct s_mrt_camera *cam, const struct s_mrt_image *img);

#endif