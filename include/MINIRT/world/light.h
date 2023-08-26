/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:52 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 16:08:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_objects.h"

struct s_mrt_light_ambient
{
};

struct s_mrt_light_ambient	*mrt_light_ambient(\
struct s_mrt_scene_light_ambient *ambient_light);

struct s_mrt_light_point
{
};

struct s_mrt_light_point	*mrt_light_point(\
struct s_mrt_scene_light_point *point_light);

#endif