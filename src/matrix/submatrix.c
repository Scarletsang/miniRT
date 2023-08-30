/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:13:29 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 17:43:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include <assert.h>

static void	mrt_submatrix_make(t_mrt_matrix matrix, t_mrt_matrix submatrix, \
unsigned int trim_row, unsigned int trim_column)
{
	double			*buffer;
	double			*submatrix_buffer;
	unsigned int	row;
	unsigned int	column;
	unsigned int	size;

	buffer = mrt_unique_ptr_get_matrix(&matrix)->matrix;
	submatrix_buffer = mrt_unique_ptr_get_matrix(&submatrix)->matrix;
	size = mrt_unique_ptr_get_matrix(&matrix)->size;
	row = 0;
	while (row < size)
	{
		if (row != trim_row)
		{
			column = 0;
			while (column < size)
			{
				if (column != trim_column)
					*submatrix_buffer++ = buffer[row * size + column];
				column++;
			}
		}
		row++;
	}
}

t_mrt_matrix	mrt_submatrix(t_mrt_matrix matrix, unsigned int trim_row, \
unsigned int trim_column)
{
	t_mrt_matrix			submatrix;

	submatrix = mrt_unique_matrix(matrix.allocator);
	if (mrt_unique_ptr_is_empty(&submatrix))
	{
		mrt_unique_ptr_free(&matrix);
		return (mrt_unique_ptr_empty());
	}
	assert(mrt_unique_ptr_get_matrix(&matrix)->size > 2 && \
		trim_row < mrt_unique_ptr_get_matrix(&matrix)->size && \
		trim_column < mrt_unique_ptr_get_matrix(&matrix)->size);
	mrt_unique_ptr_get_matrix(&submatrix)->size = \
		mrt_unique_ptr_get_matrix(&matrix)->size - 1;
	mrt_submatrix_make(matrix, submatrix, trim_row, trim_column);
	mrt_unique_ptr_free(&matrix);
	return (submatrix);
}
