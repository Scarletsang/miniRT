/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:05:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 18:44:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# include "MINIRT/unit/vec2.h"
# include "MINIRT/unit/vec3.h"
# include "MINIRT/unit/color.h"
# include "MINIRT/unit/range.h"

typedef t_mrt_vec3	t_mrt_point3d;
typedef t_mrt_vec3	t_mrt_direction3d;
typedef t_mrt_vec3	t_mrt_direction3d_unit;

typedef t_mrt_vec2	t_mrt_dimension;

/**
 * @brief ratio is a float between 0 and 1
 */
typedef double		t_mrt_ratio;
typedef double		t_mrt_degrees;

#endif