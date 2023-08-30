/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:49:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 17:34:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/memory.h"
#include <assert.h>

inline t_mrt_vec4	vec4(double x, double y, double z, double w)
{
	return ((t_mrt_vec4){\
		.x = x, \
		.y = y, \
		.z = z, \
		.w = w
	});
}

t_mrt_matrix	mrt_matrix_identity(struct s_mrt_allocator *allocator)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;

	matrix = mrt_unique_matrix(allocator);
	if (mrt_unique_ptr_is_empty(&matrix))
		return (mrt_unique_ptr_empty());
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	internal_matrix->size = 4;
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->matrix[0] = 1;
	internal_matrix->matrix[5] = 1;
	internal_matrix->matrix[10] = 1;
	internal_matrix->matrix[15] = 1;
	return (matrix);
}
