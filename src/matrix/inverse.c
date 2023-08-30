/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:28:47 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 17:47:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"

static void	mrt_matrix_inverse_make(t_mrt_matrix *matrix, \
t_mrt_matrix *inversed_matrix, double determinant)
{
	unsigned int			row;
	unsigned int			column;
	unsigned int			size;

	size = mrt_unique_ptr_get_matrix(matrix)->size;
	row = 0;
	while (row < size)
	{
		column = 0;
		while (column < size)
		{
			mrt_internal_matrix_set(mrt_unique_ptr_get_matrix(inversed_matrix), \
				column, row, mrt_cofactor(mrt_borrow(*matrix), row, column) / \
				determinant);
			column++;
		}
		row++;
	}
}

t_mrt_matrix	mrt_matrix_inverse(t_mrt_matrix matrix)
{
	double			determinant;
	t_mrt_matrix	inversed_matrix;

	inversed_matrix = mrt_unique_matrix(matrix.allocator);
	determinant = mrt_determinant(mrt_borrow(matrix));
	if (mrt_unique_ptr_is_empty(&inversed_matrix) || determinant == 0)
	{
		mrt_unique_ptr_free(&matrix);
		return (mrt_unique_ptr_empty());
	}
	mrt_matrix_inverse_make(&matrix, &inversed_matrix, determinant);
	mrt_unique_ptr_free(&matrix);
	return (inversed_matrix);
}
