/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:18:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 17:55:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/unit.h"
#include <math.h>

t_mrt_matrix	mrt_matrix_rotate_x(struct s_mrt_allocator *allocator, \
double radians)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;
	double					cosine;
	double					sine;

	matrix = mrt_unique_matrix(allocator);
	if (mrt_unique_ptr_is_empty(&matrix))
		return (mrt_unique_ptr_empty());
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->size = 4;
	sine = sin(radians);
	cosine = cos(radians);
	internal_matrix->matrix[0] = 1;
	internal_matrix->matrix[5] = cosine;
	internal_matrix->matrix[6] = -sine;
	internal_matrix->matrix[9] = sine;
	internal_matrix->matrix[10] = cosine;
	internal_matrix->matrix[15] = 1;
	return (matrix);
}

t_mrt_matrix	mrt_matrix_rotate_y(struct s_mrt_allocator *allocator, \
double radians)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;
	double					cosine;
	double					sine;

	matrix = mrt_unique_matrix(allocator);
	if (mrt_unique_ptr_is_empty(&matrix))
		return (mrt_unique_ptr_empty());
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->size = 4;
	sine = sin(radians);
	cosine = cos(radians);
	internal_matrix->matrix[0] = cosine;
	internal_matrix->matrix[2] = sine;
	internal_matrix->matrix[5] = 1;
	internal_matrix->matrix[8] = -sine;
	internal_matrix->matrix[10] = cosine;
	internal_matrix->matrix[15] = 1;
	return (matrix);
}

t_mrt_matrix	mrt_matrix_rotate_z(struct s_mrt_allocator *allocator, \
double radians)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;
	double					cosine;
	double					sine;

	matrix = mrt_unique_matrix(allocator);
	if (mrt_unique_ptr_is_empty(&matrix))
		return (mrt_unique_ptr_empty());
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->size = 4;
	sine = sin(radians);
	cosine = cos(radians);
	internal_matrix->matrix[0] = cosine;
	internal_matrix->matrix[1] = -sine;
	internal_matrix->matrix[4] = sine;
	internal_matrix->matrix[5] = cosine;
	internal_matrix->matrix[10] = 1;
	internal_matrix->matrix[15] = 1;
	return (matrix);
}
