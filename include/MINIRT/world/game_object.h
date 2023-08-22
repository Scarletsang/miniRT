/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:20 by htsang            #+#    #+#             */
/*   Updated: 2023/08/22 12:17:51 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_game_object.h"

struct s_mrt_ray;

struct s_mrt_sphere
{
	struct s_mrt_scene_sphere	*scene;
};

struct s_mrt_sphere		*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere);
bool	mrt_sphere_is_hit(struct s_mrt_ray *ray, struct s_mrt_sphere *sphere);
void	mrt_sphere_free(struct s_mrt_sphere *sphere);

struct s_mrt_plane
{
	struct s_mrt_scene_plane	*scene;
};

struct s_mrt_plane		*mrt_plane(struct s_mrt_scene_plane *scene_plane);
bool	mrt_plane_is_hit(struct s_mrt_ray *ray, struct s_mrt_plane *plane);

struct s_mrt_cylinder
{
	struct s_mrt_scene_cylinder	*scene;
};

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_cylinder);
bool	mrt_cylinder_is_hit(struct s_mrt_ray *ray \
	, struct s_mrt_cylinder *cylinder);

#endif