/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:52 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 12:04:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_objects.h"

struct s_mrt_light_ambient
{
	struct s_mrt_scene_light_ambient	*scene;
	t_mrt_percentage					color;
};

struct s_mrt_light_ambient	*mrt_light_ambient(\
struct s_mrt_scene_light_ambient *ambient_light);

void						mrt_light_ambient_refresh(\
struct s_mrt_light_ambient *light_ambient);

void						mrt_light_ambient_free(\
struct s_mrt_light_ambient *light_ambient);

struct s_mrt_light_point
{
	struct s_mrt_scene_light_point	*scene;
	t_mrt_percentage				color;
};

struct s_mrt_light_point	*mrt_light_point(\
struct s_mrt_scene_light_point *point_light);

void						mrt_light_point_refresh(\
struct s_mrt_light_point *light_point);

void						mrt_light_point_free(\
struct s_mrt_light_point *light_point);

#endif