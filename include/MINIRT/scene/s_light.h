/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_light.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:52 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 16:31:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_LIGHT_H
# define S_LIGHT_H

# include "MINIRT/unit.h"

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