/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:51:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "MINIRT/unit.h"

struct s_mrt_scene_camera
{
	t_mrt_point3d			origin;
	t_mrt_direction3d_unit	orientation; // unused for now
	t_mrt_degrees			fov; // unused for now
};

struct s_mrt_scene_camera	*mrt_scene_camera(t_mrt_point3d origin, \
t_mrt_direction3d_unit orientation, t_mrt_degrees fov);

struct s_mrt_scene_camera	*mrt_scene_camera_default(void);

#endif