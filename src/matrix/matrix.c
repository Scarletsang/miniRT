/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:49:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 17:28:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/matrix.h"
#include "MINIRT/memory.h"
#include <assert.h>
#include <stdio.h>

inline t_mrt_vec4	vec4(double x, double y, double z, double w)
{
	return ((t_mrt_vec4){\
		.x = x, \
		.y = y, \
		.z = z, \
		.w = w
	});
}

void	mrt_matrix_print(t_mrt_matrix matrix)
{
	t_mrt_internal_matrix	*internal_matrix;
	unsigned int			i;

	internal_matrix = mrt_unique_ptr_get_matrix(&matrix);
	i = 0;
	while (i < internal_matrix->size * internal_matrix->size)
	{
		if (i % internal_matrix->size == 0)
			printf("\n");
		printf("%f ", internal_matrix->matrix[i]);
		i++;
	}
	printf("\n");
}
