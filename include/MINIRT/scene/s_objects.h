/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_objects.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 12:30:44 by kisikogl         ###   ########.fr       */
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

void	mrt_scene_camera_print(struct s_mrt_scene_camera *camera);

////////////////////////////////////
////////////   lights   ////////////
////////////////////////////////////

struct s_mrt_scene_light_ambient
{
	t_mrt_ratio	ratio;
	t_mrt_color	color;
};

void	mrt_scene_light_ambient_print(\
struct s_mrt_scene_light_ambient *light_ambient);

struct s_mrt_scene_light_point
{
	t_mrt_point3d	origin;
	t_mrt_ratio		ratio;
	t_mrt_color		color;
};

void	mrt_scene_light_point_print(\
struct s_mrt_scene_light_point *light_point);

//////////////////////////////////////////////////
////////////   geometric constructs   ////////////
//////////////////////////////////////////////////

struct s_mrt_scene_sphere
{
	t_mrt_point3d	center;
	double			diameter;
	t_mrt_color		color;
};

void	mrt_scene_sphere_print(struct s_mrt_scene_sphere *sphere);

struct s_mrt_scene_plane
{
	t_mrt_point3d	point;
	t_mrt_vec3_unit	normal;
	t_mrt_color		color;
};

void	mrt_scene_plane_print(struct s_mrt_scene_plane *plane);

struct s_mrt_scene_cylinder
{
	t_mrt_point3d	center;
	t_mrt_vec3_unit	orientation;
	double			diameter;
	double			height;
	t_mrt_color		color;
};

void	mrt_scene_cylinder_print(struct s_mrt_scene_cylinder *cylinder);

#endif