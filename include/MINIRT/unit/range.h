/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:02:44 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 11:10:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGE_H
# define RANGE_H

# include "vec2.h"

typedef t_mrt_vec2	t_mrt_range;

t_mrt_range	mrt_range(double min, double max);

double		mrt_range_minimum(t_mrt_range range);

double		mrt_range_maximum(t_mrt_range range);

double		mrt_range_size(t_mrt_range range);

#endif