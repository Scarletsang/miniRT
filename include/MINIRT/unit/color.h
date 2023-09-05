/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:02:14 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 17:10:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "MINIRT/unit/vec3.h"

typedef t_mrt_vec3	t_mrt_color;

t_mrt_vec3_unit	mrt_color_unit(t_mrt_color color);

t_mrt_color		mrt_vec3_unit_color(t_mrt_vec3_unit unit);

#endif