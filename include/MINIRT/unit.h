/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:05:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 10:35:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_H
# define UNIT_H

# include "MINIRT/unit/vec2.h"
# include "MINIRT/unit/vec3.h"
# include "MINIRT/unit/color.h"
# include "MINIRT/unit/range.h"
# include <stdbool.h>

void					vec3_print(t_mrt_vec3 v);

typedef t_mrt_vec3	t_mrt_point3d;

t_mrt_point3d			mrt_point3d_origin(void);

typedef t_mrt_vec3	t_mrt_direction3d;
typedef t_mrt_vec3	t_mrt_direction3d_unit;

t_mrt_direction3d_unit	mrt_direction3d_unit_empty(void);

bool					mrt_direction3d_unit_is_empty(\
t_mrt_direction3d_unit *unit);

typedef t_mrt_vec2	t_mrt_dimension;

/**
 * @brief ratio is a float between 0 and 1
 */
typedef double		t_mrt_ratio;
typedef double		t_mrt_degrees;

#endif