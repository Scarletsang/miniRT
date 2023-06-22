/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:02:44 by htsang            #+#    #+#             */
/*   Updated: 2023/06/23 00:11:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGE_H
# define RANGE_H

# include "vec2.h"

typedef t_mrt_vec2	t_mrt_range;

t_mrt_range	mrt_range(float min, float max);

float		mrt_range_minimum(t_mrt_range range);

float		mrt_range_maximum(t_mrt_range range);

float		mrt_range_size(t_mrt_range range);

#endif