/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:17:46 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 18:19:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/memory.h"
#include "LIBFT/string.h"
#include <stdbool.h>
#include <assert.h>

static void	mrt_matrix4x4_multiply_run(\
t_mrt_internal_matrix *internal_matrix1, \
t_mrt_internal_matrix *internal_matrix2, \
t_mrt_internal_matrix *internal_matrix3)
{
	unsigned int	row;
	unsigned int	column;

	row = 0;
	while (row++ < 4)
	{
		column = 0;
		while (column++ < 4)
		{
			mrt_internal_matrix_set(internal_matrix3, column, row, \
			mrt_internal_matrix_get(internal_matrix1, 0, row) * \
			mrt_internal_matrix_get(internal_matrix2, column, 0) + \
			mrt_internal_matrix_get(internal_matrix1, 1, row) * \
			mrt_internal_matrix_get(internal_matrix2, column, 1) + \
			mrt_internal_matrix_get(internal_matrix1, 2, row) * \
			mrt_internal_matrix_get(internal_matrix2, column, 2) + \
			mrt_internal_matrix_get(internal_matrix1, 3, row) * \
			mrt_internal_matrix_get(internal_matrix2, column, 3));
		}
	}
	internal_matrix3->size = 4;
}

/**
 * @brief Multiply two 4x4 matrices
*/
t_mrt_matrix	mrt_matrix_multiply(t_mrt_matrix matrix1, \
t_mrt_matrix matrix2)
{
	t_mrt_internal_matrix	*internal_matrix1;
	t_mrt_internal_matrix	*internal_matrix2;
	t_mrt_unique_ptr		unique_matrix3;

	internal_matrix1 = mrt_unique_ptr_get_matrix(&matrix1);
	internal_matrix2 = mrt_unique_ptr_get_matrix(&matrix2);
	assert(internal_matrix1->size == internal_matrix2->size && \
		internal_matrix1->size == 4);
	unique_matrix3 = mrt_unique_matrix(matrix1.allocator);
	if (mrt_unique_ptr_is_empty(&unique_matrix3))
		return (mrt_unique_ptr_empty());
	mrt_matrix4x4_multiply_run(internal_matrix1, internal_matrix2, \
		mrt_unique_ptr_get_matrix(&unique_matrix3));
	mrt_unique_ptr_free(&matrix1);
	mrt_unique_ptr_free(&matrix2);
	return (unique_matrix3);
}

t_mrt_vec4	mrt_matrix_apply(t_mrt_matrix matrix, t_mrt_vec4 vec4)
{
	t_mrt_internal_matrix	*internal_matrix;
	t_mrt_vec4				result;

	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	assert(internal_matrix->size == 4);
	result.x = mrt_internal_matrix_get(internal_matrix, 0, 0) * vec4.x + \
		mrt_internal_matrix_get(internal_matrix, 1, 0) * vec4.y + \
		mrt_internal_matrix_get(internal_matrix, 2, 0) * vec4.z + \
		mrt_internal_matrix_get(internal_matrix, 3, 0) * vec4.w;
	result.y = mrt_internal_matrix_get(internal_matrix, 0, 1) * vec4.x + \
		mrt_internal_matrix_get(internal_matrix, 1, 1) * vec4.y + \
		mrt_internal_matrix_get(internal_matrix, 2, 1) * vec4.z + \
		mrt_internal_matrix_get(internal_matrix, 3, 1) * vec4.w;
	result.z = mrt_internal_matrix_get(internal_matrix, 0, 2) * vec4.x + \
		mrt_internal_matrix_get(internal_matrix, 1, 2) * vec4.y + \
		mrt_internal_matrix_get(internal_matrix, 2, 2) * vec4.z + \
		mrt_internal_matrix_get(internal_matrix, 3, 2) * vec4.w;
	result.w = mrt_internal_matrix_get(internal_matrix, 0, 3) * vec4.x + \
		mrt_internal_matrix_get(internal_matrix, 1, 3) * vec4.y + \
		mrt_internal_matrix_get(internal_matrix, 2, 3) * vec4.z + \
		mrt_internal_matrix_get(internal_matrix, 3, 3) * vec4.w;
	mrt_unique_ptr_free(&matrix);
	return (result);
}
