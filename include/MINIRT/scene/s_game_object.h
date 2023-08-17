/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_game_object.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:20 by htsang            #+#    #+#             */
/*   Updated: 2023/08/14 11:50:31 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_GAME_OBJECT_H
# define S_GAME_OBJECT_H

# include "MINIRT/unit.h"


struct s_mrt_scene_sphere
{
	t_mrt_point3d	center;
	double			diameter;
	t_mrt_color		color;
};

struct s_mrt_scene_entry	mrt_scene_sphere( \
t_mrt_point3d center, double diameter, t_mrt_color color);

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

#endif