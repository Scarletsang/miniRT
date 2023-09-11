/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:15:36 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 16:07:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"

static void	mrt_scene_parser_vec3_error_trace(t_mrt_unit_parser_atom result, \
t_mrt_range *range)
{
	enum e_mrt_parser_expected_code	expected_code;

	if (!range)
		expected_code = MRT_PARSER_EXPECT_VEC3;
	else if (range->x == -1 && range->y == 1)
		expected_code = MRT_PARSER_EXPECT_UNIT_VEC3;
	else if (range->x == 0 && range->y == 1)
		expected_code = MRT_PARSER_EXPECT_PERCENTAGE;
	else
		expected_code = MRT_PARSER_EXPECT_VEC3;
	ft_parser_atom_add_error_trace(result, expected_code, \
		MRT_PARSER_ERROR_INVALID_SYNTAX);
}

t_mrt_unit_parser_atom	mrt_scene_parser_vec3(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object)
{
	t_mrt_unit_parser_atom			result;

	result = mrt_parser_vec3_float(input, range_object);
	if (!result.is_valid)
	{
		mrt_scene_parser_vec3_error_trace(result, \
			(t_mrt_range *) range_object.as_ptr);
	}
	return (result);
}

t_mrt_unit_parser_atom	mrt_scene_parser_float(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object)
{
	return (ft_decorator_value_as_ptr(\
		ft_parser_entity(&mrt_parser_float, range_object), \
		input, ft_tobject_int(FT_TOBJECT_FLOAT)));
}

t_mrt_unit_parser_atom	mrt_scene_parser_color(\
t_mrt_unit_parser_atom input, union u_ft_tobject option)
{
	t_mrt_range				range;
	t_mrt_unit_parser_atom	result;

	(void) option;
	range = mrt_range(0.0, 255.0);
	result = mrt_parser_vec3_uint(input, ft_tobject_ptr(&range));
	if (!result.is_valid)
		ft_parser_atom_add_error_trace(result, MRT_PARSER_EXPECT_COLOR, \
			MRT_PARSER_ERROR_INVALID_SYNTAX);
	return (result);
}
