/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:56:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_camera.h"
# include "MINIRT/image.h"

struct s_mrt_viewport
{
	t_mrt_dimension	dimension;
	t_mrt_vec3		lower_left_corner;
	t_mrt_vec3		horizontal;
	t_mrt_vec3		vertical;
};

// need to add orientation and fov later
struct s_mrt_camera
{
	struct s_mrt_scene_camera	*world;
	struct s_mrt_image			screen;
	struct s_mrt_viewport		viewport;
	double						focal_length;
};

struct s_mrt_camera	*mrt_camera(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length);

void				mrt_camera_free(struct s_mrt_camera *camera);

t_mrt_vec3			mrt_camera_lower_left_corner_calculate(\
struct s_mrt_camera *camera);

struct s_mrt_camera	*mrt_camera_default(void);

#endif