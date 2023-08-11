/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:20 by htsang            #+#    #+#             */
/*   Updated: 2023/08/11 12:34:08 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_game_object.h"
# include "MINIRT/ray.h"

struct s_mrt_sphere
{
};

struct s_mrt_sphere		*mrt_sphere(struct s_mrt_scene_sphere *scene_sphere);
bool	mrt_sphere_is_hit(t_mrt_ray *ray, t_mrt_point3d center, double radius);

struct s_mrt_plane
{
};

struct s_mrt_plane		*mrt_plane(struct s_mrt_scene_plane *scene_sphere);

struct s_mrt_cylinder
{
};

struct s_mrt_cylinder	*mrt_cylinder(\
struct s_mrt_scene_cylinder *scene_sphere);

#endif