/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/08/07 20:19:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_camera.h"
# include "MINIRT/image.h"

/**
 * @brief A viewport describes all the necessary details for a camera to render
 * a scene on a screen. All the fields are stored for purpose of caching, so
 * that one do not need to recompute them every time a ray is cast.
*/
struct s_mrt_viewport
{
	t_mrt_dimension	dimension;
	t_mrt_vec3		lower_left_corner;
	t_mrt_vec3		horizontal;
	t_mrt_vec3		vertical;
	t_mrt_vec3		pixel_horizontal;
	t_mrt_vec3		pixel_vertical;
};

struct s_mrt_viewport	mrt_viewport(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length);

// need to add orientation and fov later
struct s_mrt_camera
{
	struct s_mrt_scene_camera	*world;
	struct s_mrt_image			screen;
	struct s_mrt_viewport		viewport;
	double						focal_length;
};

struct s_mrt_camera		*mrt_camera(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_image screen, double focal_length);

void					mrt_camera_free(struct s_mrt_camera *camera);

void					mrt_camera_refresh(struct s_mrt_camera *camera);

struct s_mrt_camera		*mrt_camera_default(void);

#endif