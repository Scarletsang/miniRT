/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:07:43 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 22:01:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "MINIRT/memory.h"
# include "MINIRT/unit.h"

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

t_mrt_matrix		mrt_matrix_identity(struct s_mrt_allocator *allocator);

t_mrt_matrix		mrt_matrix_scale(struct s_mrt_allocator *allocator, \
t_mrt_vec3 translation);

t_mrt_matrix		mrt_matrix_translation(struct s_mrt_allocator *allocator, \
t_mrt_vec3 translation);

t_mrt_matrix		mrt_matrix_rotate_x(struct s_mrt_allocator *allocator, \
double radians);

t_mrt_matrix		mrt_matrix_rotate_y(struct s_mrt_allocator *allocator, \
double radians);

t_mrt_matrix		mrt_matrix_rotate_z(struct s_mrt_allocator *allocator, \
double radians);

t_mrt_matrix		mrt_matrix_shearing(struct s_mrt_allocator *allocator, \
t_mrt_vec2 xy_xz, t_mrt_vec2 yx_yz, t_mrt_vec2 zx_zy);

void				mrt_matrix_print(t_mrt_matrix matrix);

///////////////////////////////////////////////
////////////   matrix operations   ////////////
///////////////////////////////////////////////

t_mrt_matrix		mrt_matrix_multiply(t_mrt_matrix unique_matrix1, \
t_mrt_matrix unique_matrix2);

t_mrt_vec4			mrt_matrix_apply(t_mrt_matrix unique_matrix, \
t_mrt_vec4 vec4);

t_mrt_matrix		mrt_matrix_transpose(t_mrt_matrix matrix);

t_mrt_matrix		mrt_matrix_inverse(t_mrt_matrix matrix);

////////////////////////////////////////////////////////////
////////////   matrix determinant caluclation   ////////////
////////////////////////////////////////////////////////////

t_mrt_matrix		mrt_submatrix(t_mrt_matrix matrix, \
unsigned int trim_column, unsigned int trim_row);

double				mrt_minor(t_mrt_matrix matrix, unsigned int trim_column, \
unsigned int trim_row);

double				mrt_cofactor(t_mrt_matrix matrix, unsigned int trim_column, \
unsigned int trim_row);

double				mrt_determinant(t_mrt_matrix matrix);

#endif