/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:20 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:20:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_objects.h"

struct	s_mrt_ray;

struct s_mrt_sphere
{
	struct s_mrt_scene_sphere	*scene;
};

struct s_mrt_sphere		*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere);

bool					mrt_sphere_is_hit(struct s_mrt_ray *ray, \
struct s_mrt_sphere *sphere);

void					mrt_sphere_free(struct s_mrt_sphere *sphere);

struct s_mrt_plane
{
	struct s_mrt_scene_plane	*scene;
};

struct s_mrt_plane		*mrt_plane(struct s_mrt_scene_plane *scene_sphere);

bool					mrt_plane_is_hit(struct s_mrt_ray *ray, \
struct s_mrt_plane *plane);

struct s_mrt_cylinder
{
	struct s_mrt_scene_cylinder	*scene;
};

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_sphere);

bool					mrt_cylinder_is_hit(struct s_mrt_ray *ray, \
struct s_mrt_cylinder *cylinder);

#endif