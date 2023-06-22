/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:06:52 by htsang            #+#    #+#             */
/*   Updated: 2023/06/23 00:11:17 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "unit.h"

struct s_mrt_ambient_light
{
	t_mrt_ratio	ratio;
	t_mrt_color	color;
};

struct s_mrt_light
{
	t_mrt_point3d	origin;
	t_mrt_ratio		ratio;
	t_mrt_color		color;
};

#endif