/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_object.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:20 by htsang            #+#    #+#             */
/*   Updated: 2023/06/23 00:11:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OBJECT_H
# define GAME_OBJECT_H

# include "unit.h"

struct s_mrt_sphere
{
	t_mrt_point3d	center;
	float			diameter;
	t_mrt_color		color;
};

struct s_mrt_plane
{
	t_mrt_point3d	origin;
	t_mrt_vec3_unit	orientation;
	t_mrt_color		color;
};

struct s_mrt_cylinder
{
	t_mrt_point3d	center;
	t_mrt_vec3_unit	orientation;
	float			diameter;
	float			height;
	t_mrt_color		color;
};

#endif