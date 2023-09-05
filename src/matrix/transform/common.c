/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:51:38 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 17:55:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/unit.h"
#include <math.h>

t_mrt_matrix	mrt_matrix_identity(struct s_mrt_allocator *allocator)
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
	return (matrix);
}

t_mrt_matrix	mrt_matrix_scale(struct s_mrt_allocator *allocator, \
t_mrt_vec3 translation)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;

	matrix = mrt_unique_matrix(allocator);
	if (mrt_unique_ptr_is_empty(&matrix))
		return (mrt_unique_ptr_empty());
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->size = 4;
	internal_matrix->matrix[0] = translation.x;
	internal_matrix->matrix[5] = translation.y;
	internal_matrix->matrix[10] = translation.z;
	internal_matrix->matrix[15] = 1;
	return (matrix);
}

t_mrt_matrix	mrt_matrix_translation(struct s_mrt_allocator *allocator, \
t_mrt_vec3 translation)
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
	internal_matrix->matrix[3] = translation.x;
	internal_matrix->matrix[7] = translation.y;
	internal_matrix->matrix[11] = translation.z;
	return (matrix);
}
