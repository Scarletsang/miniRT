/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:00:58 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 04:52:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MRT_PARSER_TEST_HPP
# define MRT_PARSER_TEST_HPP

# include <gtest/gtest.h>

extern "C"
{
  #include "LIBFT/vector.h"
  #include "MINIRT/unit/range.h"
  #include "MINIRT/unit/vec3.h"
  #include "MINIRT/scene.h"
  #include "MINIRT/scene/s_camera.h"
  #include "MINIRT/scene/s_game_object.h"
  #include "MINIRT/scene/s_light.h"
	#include "MINIRT/parser/general_parser.h"
  #include "MINIRT/parser/scene_parser.h"
}

class ModuleTest : public ::testing::TestWithParam<const char *>
{
	protected:
		void	SetUp() override;
		void	TearDown() override;
};

#endif
