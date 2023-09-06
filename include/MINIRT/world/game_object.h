/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:20 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 12:53:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_objects.h"
# include <stdbool.h>

struct	s_mrt_world_entry;
struct	s_mrt_ray;

struct s_mrt_sphere
{
	struct s_mrt_scene_sphere	*scene;
	t_mrt_percentage			color;
};

struct s_mrt_sphere		*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere);

void					mrt_sphere_refresh(struct s_mrt_sphere *sphere);

void					mrt_sphere_free(struct s_mrt_sphere *sphere);

struct s_mrt_plane
{
	struct s_mrt_scene_plane	*scene;
	t_mrt_percentage			color;
};

struct s_mrt_plane		*mrt_plane(struct s_mrt_scene_plane *scene_plane);

void					mrt_plane_refresh(struct s_mrt_plane *plane);

void					mrt_plane_free(struct s_mrt_plane *plane);

struct s_mrt_cylinder
{
	struct s_mrt_scene_cylinder	*scene;
	t_mrt_percentage			color;
};

struct s_mrt_cylinder	*mrt_cylinder(\
	struct s_mrt_scene_cylinder *scene_cylinder);

void					mrt_cylinder_refresh(struct s_mrt_cylinder *cylinder);

void					mrt_cylinder_free(struct s_mrt_cylinder *cylinder);

#endif