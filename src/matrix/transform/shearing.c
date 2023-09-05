/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:19:30 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 17:56:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/unit.h"
#include <math.h>

t_mrt_matrix	mrt_matrix_shearing(struct s_mrt_allocator *allocator, \
t_mrt_vec2 xy_xz, t_mrt_vec2 yx_yz, t_mrt_vec2 zx_zy)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;

	matrix = mrt_unique_matrix(allocator);
	if (mrt_unique_ptr_is_empty(&matrix))
		return (mrt_unique_ptr_empty());
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->size = 4;
	internal_matrix->matrix[0] = 1;
	internal_matrix->matrix[5] = 1;
	internal_matrix->matrix[10] = 1;
	internal_matrix->matrix[15] = 1;
	internal_matrix->matrix[1] = xy_xz.x;
	internal_matrix->matrix[2] = xy_xz.y;
	internal_matrix->matrix[4] = yx_yz.x;
	internal_matrix->matrix[6] = yx_yz.y;
	internal_matrix->matrix[8] = zx_zy.x;
	internal_matrix->matrix[9] = zx_zy.y;
	return (matrix);
}
