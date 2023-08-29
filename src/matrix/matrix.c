/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:49:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/29 23:23:55 by htsang           ###   ########.fr       */
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

static inline void	mrt_internal_matrix_buffer_set(double *buffer, \
t_mrt_vec4 vec4)
{
	buffer[0] = vec4.x;
	buffer[1] = vec4.y;
	buffer[2] = vec4.z;
	buffer[3] = vec4.w;
}

t_mrt_matrix	mrt_matrix_identity(struct s_mrt_allocator *allocator)
{
	t_mrt_matrix			matrix;
	t_mrt_internal_matrix	*internal_matrix;

	matrix = mrt_unique_matrix(allocator);
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	internal_matrix->size = 4;
	mrt_internal_matrix_empty(internal_matrix);
	internal_matrix->matrix[0] = 1;
	internal_matrix->matrix[5] = 1;
	internal_matrix->matrix[10] = 1;
	internal_matrix->matrix[15] = 1;
	return (matrix);
}

/**
 * @brief transpose a 4x4 matrix
*/
t_mrt_matrix	mrt_matrix_transpose(t_mrt_matrix matrix)
{
	t_mrt_matrix	transposed_matrix;
	double			*transposed_buffer;
	double			*buffer;

	transposed_matrix = mrt_unique_matrix(matrix.allocator);
	mrt_unique_ptr_get_matrix(&transposed_matrix)->size = 4;
	transposed_buffer = mrt_unique_ptr_get_matrix(&transposed_matrix)->matrix;
	buffer = mrt_unique_ptr_get_matrix(&matrix)->matrix;
	mrt_internal_matrix_buffer_set(transposed_buffer, vec4(\
		buffer[0], buffer[4], buffer[8], buffer[12]));
	mrt_internal_matrix_buffer_set(transposed_buffer + 4, vec4(\
		buffer[1], buffer[5], buffer[9], buffer[13]));
	mrt_internal_matrix_buffer_set(transposed_buffer + 8, vec4(\
		buffer[2], buffer[6], buffer[10], buffer[14]));
	mrt_internal_matrix_buffer_set(transposed_buffer + 12, vec4(\
		buffer[3], buffer[7], buffer[11], buffer[15]));
	mrt_unique_ptr_free(&matrix);
	return (transposed_matrix);
}

/**
 * TODO: Move columns and rows
*/
t_mrt_matrix	mrt_submatrix(t_mrt_matrix matrix, unsigned int trim_row, \
unsigned int trim_column)
{
	t_mrt_matrix			submatrix;
	t_mrt_internal_matrix	*internal_matrix;
	t_mrt_internal_matrix	*internal_submatrix;

	submatrix = mrt_unique_matrix(matrix.allocator);
	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	internal_submatrix = mrt_unique_ptr_get_matrix(&submatrix);
	assert(internal_matrix->size > 2 && trim_row < internal_matrix->size && \
		trim_column < internal_matrix->size);
	*internal_submatrix = *internal_matrix;
	mrt_unique_ptr_free(&matrix);
	return (submatrix);
}
