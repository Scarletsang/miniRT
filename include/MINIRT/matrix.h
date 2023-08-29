/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:07:43 by htsang            #+#    #+#             */
/*   Updated: 2023/08/29 22:49:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "MINIRT/memory.h"

//////////////////////////////////
////////////   vec4   ////////////
//////////////////////////////////

typedef struct s_mrt_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_mrt_vec4;

t_mrt_vec4			vec4(double x, double y, double z, double w);

/////////////////////////////////////////////
////////////   internal matrix   ////////////
/////////////////////////////////////////////

typedef struct s_mrt_internal_matrix
{
	double			matrix[16];
	unsigned int	size;
}				t_mrt_internal_matrix;

double				mrt_internal_matrix_get(t_mrt_internal_matrix *matrix, \
unsigned int x, unsigned int y);

void				mrt_internal_matrix_set(t_mrt_internal_matrix *matrix, \
unsigned int x, unsigned int y, double value);

void				mrt_internal_matrix_empty(t_mrt_internal_matrix *matrix);

////////////////////////////////////
////////////   matrix   ////////////
////////////////////////////////////

typedef t_mrt_unique_ptr	t_mrt_matrix;

t_mrt_matrix		mrt_matrix_multiply(t_mrt_matrix unique_matrix1, \
t_mrt_matrix unique_matrix2);

t_mrt_vec4			mrt_matrix_apply(t_mrt_matrix unique_matrix, \
t_mrt_vec4 vec4);

t_mrt_matrix		mrt_matrix_identity(struct s_mrt_allocator *allocator);

t_mrt_matrix		mrt_matrix_transpose(t_mrt_matrix matrix);

#endif