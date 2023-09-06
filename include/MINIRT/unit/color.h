/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:02:14 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 12:54:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "MINIRT/unit/vec3.h"

typedef t_mrt_vec3	t_mrt_color;
typedef t_mrt_vec3	t_mrt_percentage;

t_mrt_percentage	mrt_color_to_percentage(t_mrt_color color);

t_mrt_color			mrt_vec3_unit_to_color(t_mrt_vec3_unit unit);

t_mrt_color			mrt_percentage_to_color(t_mrt_percentage percentage);

t_mrt_percentage	mrt_percentage_clamp(t_mrt_percentage percentage);

#endif