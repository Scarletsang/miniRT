/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:05:23 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 12:03:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# include "unit/vec2.h"
# include "unit/vec3.h"
# include "unit/color.h"
# include "unit/range.h"

typedef t_mrt_vec3	t_mrt_point3d;
typedef t_mrt_vec3	t_mrt_direction3d;
typedef t_mrt_vec3	t_mrt_direction3d_unit;

/**
 * @brief ratio is a float between 0 and 1
 */
typedef float		t_mrt_ratio;
typedef float		t_mrt_degrees;

#endif