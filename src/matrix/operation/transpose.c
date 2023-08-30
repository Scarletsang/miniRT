/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:12:56 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 17:34:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"

static inline void	mrt_internal_matrix_buffer_set(double *buffer, \
t_mrt_vec4 vec4)
{
	buffer[0] = vec4.x;
	buffer[1] = vec4.y;
	buffer[2] = vec4.z;
	buffer[3] = vec4.w;
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
	if (mrt_unique_ptr_is_empty(&transposed_matrix))
	{
		mrt_unique_ptr_free(&matrix);
		return (mrt_unique_ptr_empty());
	}
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
