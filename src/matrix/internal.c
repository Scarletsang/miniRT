/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:17:46 by htsang            #+#    #+#             */
/*   Updated: 2023/08/29 23:17:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include <stdbool.h>
#include <assert.h>

double	mrt_internal_matrix_get(t_mrt_internal_matrix *matrix, unsigned int x, \
unsigned int y)
{
	return (matrix->matrix[y * matrix->size + x]);
}

void	mrt_internal_matrix_set(t_mrt_internal_matrix *matrix, unsigned int x, \
unsigned int y, double value)
{
	matrix->matrix[y * matrix->size + x] = value;
}

void	mrt_internal_matrix_empty(t_mrt_internal_matrix *matrix)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		matrix->matrix[i] = 0;
		i++;
	}
	matrix->size = 0;
}
