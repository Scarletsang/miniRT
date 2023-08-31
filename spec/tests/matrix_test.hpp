/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/08/31 17:49:53 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_MATRIX_TEST_HPP
# define MRT_MATRIX_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
  #include "MINIRT/matrix.h"
}

class MatrixTest : public ::testing::Test
{
	protected:
    struct s_mrt_uniform_allocator allocator;
		void	SetUp() override;
		void	TearDown() override;
};

#endif
