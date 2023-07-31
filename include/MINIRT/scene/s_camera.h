/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_camera.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 16:31:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_CAMERA_H
# define S_CAMERA_H

# include "MINIRT/unit.h"

struct s_mrt_scene_camera
{
	t_mrt_point3d			origin;
	t_mrt_direction3d_unit	orientation;
	t_mrt_degrees			fov;
};

#endif