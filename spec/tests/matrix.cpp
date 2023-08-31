/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:56:58 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 19:26:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_test.hpp"

#include <iostream>

void	MatrixTest::SetUp()
{
	mrt_uniform_allocator_init(&allocator, 10, 10);
}

void	MatrixTest::TearDown()
{
	mrt_uniform_allocator_free(&allocator);
}

static void TestVec4(t_mrt_vec4 vec, float x, float y, float z, float w)
{
  EXPECT_NEAR(vec.x, x, 0.00001);
  EXPECT_NEAR(vec.y, y, 0.00001);
  EXPECT_NEAR(vec.z, z, 0.00001);
  EXPECT_NEAR(vec.w, w, 0.00001);
}

static void FillMatrix(t_mrt_matrix &matrix, double *values, size_t size)
{
  struct s_mrt_internal_matrix *internal_matrix = mrt_unique_ptr_get_matrix(\
    &matrix);

  internal_matrix->size = static_cast<unsigned int>(sqrt(static_cast<double>(\
    size)));
  for (size_t i = 0; i < size; i++)
  {
    internal_matrix->matrix[i] = values[i];
  }
}

static void CompareMatrix(t_mrt_matrix &matrix, double *values, size_t size)
{
  struct s_mrt_internal_matrix *internal_matrix = mrt_unique_ptr_get_matrix(\
    &matrix);

  for (size_t i = 0; i < size; i++)
  {
    EXPECT_NEAR(internal_matrix->matrix[i], values[i], 0.00001);
  }
}

TEST_F(MatrixTest, identity)
{
  t_mrt_matrix  identity_matrix = mrt_matrix_identity(&allocator.matrices);
  t_mrt_vec4    input = vec4(1, 2, 3, 1);
  t_mrt_vec4    output = mrt_matrix_apply(mrt_use(&identity_matrix), input);

  TestVec4(output, 1, 2, 3, 1);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&identity_matrix), true);
}

TEST_F(MatrixTest, submatrix)
{
  t_mrt_matrix  matrix4x4     = mrt_unique_matrix(&allocator.matrices);

  FillMatrix(matrix4x4, (double[16]){
    -2, -8, 3, 5,
    -3, 1, 7, 3,
    1, 2, -9, 6,
    -6, 7, 7, -9
  }, 16);
  t_mrt_matrix  matrix3x3 = mrt_submatrix(mrt_borrow(matrix4x4), 2, 1);
  t_mrt_matrix  matrix2x2 = mrt_submatrix(mrt_borrow(matrix3x3), 2, 1);
  CompareMatrix(matrix4x4, (double[16]){
    -2, -8, 3, 5,
    -3, 1, 7, 3,
    1, 2, -9, 6,
    -6, 7, 7, -9
  }, 16);
  CompareMatrix(matrix3x3, (double[9]){
    -2, -8, 5,
    1, 2, 6,
    -6, 7, -9
  }, 9);
  CompareMatrix(matrix2x2, (double[4]){
    -2, -8,
    -6, 7
  }, 4);
  mrt_unique_ptr_free(&matrix4x4);
  mrt_unique_ptr_free(&matrix3x3);
  mrt_unique_ptr_free(&matrix2x2);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&matrix4x4), true);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&matrix3x3), true);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&matrix2x2), true);
}

TEST_F(MatrixTest, determinant2x2)
{
  t_mrt_matrix  matrix     = mrt_unique_matrix(&allocator.matrices);

  FillMatrix(matrix, (double[4]){
    1, 5,
    -3, 2
  }, 4);
  EXPECT_EQ(mrt_determinant(mrt_use(&matrix)), 17);
}

TEST_F(MatrixTest, determinant)
{
  t_mrt_matrix  matrix     = mrt_unique_matrix(&allocator.matrices);

  FillMatrix(matrix, (double[16]){
    -2, -8, 3, 5,
    -3, 1, 7, 3,
    1, 2, -9, 6,
    -6, 7, 7, -9
  }, 16);
  EXPECT_EQ(mrt_determinant(mrt_use(&matrix)), -4071);
}

TEST_F(MatrixTest, inverse)
{
  t_mrt_matrix  translation_matrix     = mrt_unique_matrix(&allocator.matrices);

  FillMatrix(translation_matrix, (double[16]){
    8, -5, 9, 2,
    7, 5, 6, 1,
    -6, 0, 9, 6,
    -3, 0, -9, -4
  }, 16);
  t_mrt_matrix  inverse_matrix = mrt_matrix_inverse(mrt_use(&translation_matrix));
  EXPECT_EQ(mrt_unique_ptr_is_empty(&translation_matrix), true);
  ASSERT_EQ(mrt_unique_ptr_is_empty(&inverse_matrix), false);

  CompareMatrix(inverse_matrix, (double[16]){
    -0.15385, -0.15385, -0.28205, -0.53846,
    -0.07692, 0.12308, 0.02564, 0.03077,
    0.35897, 0.35897, 0.43590, 0.92308,
    -0.69231, -0.69231, -0.76923, -1.92308
  }, 16);
}

TEST_F(MatrixTest, translation)
{
  t_mrt_matrix  translation_matrix = mrt_matrix_translation(&allocator.matrices, \
    vec3(1, 2, 3));
  t_mrt_vec4    input = vec4(1, 2, 3, 1);
  t_mrt_vec4    output = mrt_matrix_apply(mrt_use(&translation_matrix), input);

  TestVec4(output, 2, 4, 6, 1);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&translation_matrix), true);
}

TEST_F(MatrixTest, translation_1)
{
  t_mrt_matrix  translation_matrix = mrt_matrix_translation(&allocator.matrices, \
    vec3(5, -3, 2));
  t_mrt_vec4    input = vec4(-3, 4, 5, 1);
  t_mrt_vec4    output = mrt_matrix_apply(mrt_use(&translation_matrix), input);

  TestVec4(output, 2, 1, 7, 1);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&translation_matrix), true);
}

TEST_F(MatrixTest, translation_then_inverse)
{
  t_mrt_matrix  translation_matrix = mrt_matrix_translation(&allocator.matrices, \
    vec3(5, -3, 2));
  t_mrt_vec4    input = vec4(-3, 4, 5, 1);
  t_mrt_vec4    output = mrt_matrix_apply(\
    mrt_matrix_inverse(mrt_use(&translation_matrix)), input);

  TestVec4(output, -8, 7, 3, 1);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&translation_matrix), true);
}

TEST_F(MatrixTest, translation_does_not_work_on_vector)
{
  t_mrt_matrix  translation_matrix = mrt_matrix_translation(&allocator.matrices, \
    vec3(1, 2, 3));
  t_mrt_vec4    input = vec4(1, 2, 3, 0);
  t_mrt_vec4    output = mrt_matrix_apply(mrt_use(&translation_matrix), input);

  TestVec4(output, 1, 2, 3, 0);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&translation_matrix), true);
}

TEST_F(MatrixTest, scale)
{
  t_mrt_matrix  scale_matrix = mrt_matrix_scale(&allocator.matrices, \
    vec3(2, 3, 4));
  t_mrt_vec4    input = vec4(-4, 6, 8, 1);
  t_mrt_vec4    output = mrt_matrix_apply(mrt_use(&scale_matrix), input);

  TestVec4(output, -8, 18, 32, 1);
  EXPECT_EQ(mrt_unique_ptr_is_empty(&scale_matrix), true);
}
