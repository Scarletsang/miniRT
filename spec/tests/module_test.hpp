/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/07/02 15:13:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGBUILDER_TEST_HPP
# define STRINGBUILDER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
	#include "LIBFT/stringbuilder.h"
}

class ModuleTest : public ::testing::TestWithParam<const char *>
{
	protected:
		void	SetUp() override;
		void	TearDown() override;
};

#endif
