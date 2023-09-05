/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:14:55 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 20:50:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"

double	mrt_minor(t_mrt_matrix matrix, unsigned int trim_column, \
unsigned int trim_row)
{
	return (mrt_determinant(mrt_submatrix(matrix, trim_column, trim_row)));
}

double	mrt_cofactor(t_mrt_matrix matrix, unsigned int trim_column, \
unsigned int trim_row)
{
	if (((trim_column + trim_row) % 2) == 0)
		return (mrt_minor(matrix, trim_column, trim_row));
	else
		return (-mrt_minor(matrix, trim_column, trim_row));
}

static double	mrt_determinant_2x2(t_mrt_matrix matrix)
{
	double	determinant;

	determinant = mrt_unique_ptr_get_matrix(&matrix)->matrix[0] * \
		mrt_unique_ptr_get_matrix(&matrix)->matrix[3] - \
		mrt_unique_ptr_get_matrix(&matrix)->matrix[1] * \
		mrt_unique_ptr_get_matrix(&matrix)->matrix[2];
	mrt_unique_ptr_free(&matrix);
	return (determinant);
}

double	mrt_determinant(t_mrt_matrix matrix)
{
	double			determinant;
	unsigned int	size;
	unsigned int	column;

	determinant = 0;
	size = mrt_unique_ptr_get_matrix(&matrix)->size;
	if (size == 2)
		return (mrt_determinant_2x2(matrix));
	else
	{
		column = 0;
		while (column < size)
		{
			determinant += mrt_internal_matrix_get(\
				mrt_unique_ptr_get_matrix(&matrix), 0, column) * \
				mrt_cofactor(mrt_unique_ptr_borrow(matrix), 0, column);
			column++;
		}
	}
	mrt_unique_ptr_free(&matrix);
	return (determinant);
}
