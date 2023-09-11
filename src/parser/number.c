/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:12:08 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:56:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/general_parser.h"
#include "MINIRT/unit/range.h"
#include <stdint.h>

struct s_ft_parser_atom	mrt_parser_float(\
struct s_ft_parser_atom input, union u_ft_tobject range_object)
{
	struct s_ft_parser_atom	output;
	t_mrt_range				*range;

	output = ft_parser_float(input, ft_tobject_empty());
	if (!output.is_valid)
		return (mrt_parser_atom_with_trace(input, \
			MRT_PARSER_EXPECT_FLOAT, \
			MRT_PARSER_ERROR_INVALID_SYNTAX));
	else if (range_object.as_ptr)
	{
		range = range_object.as_ptr;
		if (output.payload.as_float > mrt_range_maximum(*range) || \
			output.payload.as_float < mrt_range_minimum(*range))
			return (mrt_parser_atom_with_trace(input, \
				MRT_PARSER_EXPECT_FLOAT, \
				MRT_PARSER_ERROR_OUT_OF_RANGE));
	}
	return (output);
}

struct s_ft_parser_atom	mrt_parser_uint(\
struct s_ft_parser_atom input, union u_ft_tobject range_object)
{
	struct s_ft_parser_atom	output;
	t_mrt_range				*range;

	output = ft_parser_uint(input, ft_tobject_empty());
	if (!output.is_valid)
		return (mrt_parser_atom_with_trace(input, \
			MRT_PARSER_EXPECT_UINT, \
			MRT_PARSER_ERROR_INVALID_SYNTAX));
	else if (range_object.as_ptr)
	{
		range = range_object.as_ptr;
		if (output.payload.as_uint > (uint32_t) mrt_range_maximum(*range) || \
			output.payload.as_uint < (uint32_t) mrt_range_minimum(*range))
			return (mrt_parser_atom_with_trace(input, \
				MRT_PARSER_EXPECT_UINT, \
				MRT_PARSER_ERROR_OUT_OF_RANGE));
	}
	return (output);
}
