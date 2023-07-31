/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 16:29:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "MINIRT/unit.h"
# include "MINIRT/image.h"

struct s_mrt_scene_camera
{
	double			viewport_height;
	double			viewport_width;
	double			focal_length;
	t_mrt_vec3		origin;
	t_mrt_vec3		horizontal;
	t_mrt_vec3		vertical;
	t_mrt_vec3		lower_left_corner;
};

struct s_mrt_scene_camera	*new_camera(const struct s_mrt_image *img);

#endif