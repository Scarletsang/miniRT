/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_objects.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 16:06:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_OBJECTS_H
# define S_OBJECTS_H

# include "MINIRT/scene.h" 
# include "MINIRT/unit.h"

////////////////////////////////////
////////////   camera   ////////////
////////////////////////////////////

// orientation and fov are unused for now
struct s_mrt_scene_camera
{
	t_mrt_point3d			origin;
	t_mrt_direction3d_unit	orientation;
	t_mrt_degrees			fov;
};

//////////////////////////////////////////////////
////////////   geometric constructs   ////////////
//////////////////////////////////////////////////

struct s_mrt_scene_sphere
{
	t_mrt_point3d	center;
	double			diameter;
	t_mrt_color		color;
};

struct s_mrt_scene_plane
{
	t_mrt_point3d	origin;
	t_mrt_vec3_unit	orientation;
	t_mrt_color		color;
};

struct s_mrt_scene_cylinder
{
	t_mrt_point3d	center;
	t_mrt_vec3_unit	orientation;
	double			diameter;
	double			height;
	t_mrt_color		color;
};

////////////////////////////////////
////////////   lights   ////////////
////////////////////////////////////

struct s_mrt_scene_light_ambient
{
	t_mrt_ratio	ratio;
	t_mrt_color	color;
};

struct s_mrt_scene_light_point
{
	t_mrt_point3d	origin;
	t_mrt_ratio		ratio;
	t_mrt_color		color;
};

#endif