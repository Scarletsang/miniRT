/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:29:16 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:43:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/parser/error_trace.h"
#include "MINIRT/parser/general_parser.h"
#include <stdio.h>

void	mrt_syntax_error_printer(int error_code)
{
	if (error_code == MRT_PARSER_ERROR_INVALID_IDENTIFIER)
		printf("invalid object identifier");
	else if (error_code == MRT_PARSER_ERROR_UNIQUE_IDENTIFIER_REPEATED)
		printf("unique object identifier repeated");
	else if (error_code == MRT_PARSER_ERROR_OUT_OF_RANGE)
		printf("out of range");
	else if (error_code == MRT_PARSER_ERROR_EXTRA_ARGUMENT)
		printf("extra argument");
	else if (error_code == MRT_PARSER_ERROR_INVALID_SYNTAX)
		printf("invalid syntax");
}

void	mrt_syntax_expected_printer(int expected_code)
{
	if (expected_code == MRT_PARSER_EXPECT_IDENTIFIER)
		printf("object identifier");
	else if (expected_code == MRT_PARSER_EXPECT_FLOAT)
		printf("float");
	else if (expected_code == MRT_PARSER_EXPECT_UINT)
		printf("unsigned integer");
	else if (expected_code == MRT_PARSER_EXPECT_VEC3)
		printf("vec3 (3 floating point separated by commas)");
	else if (expected_code == MRT_PARSER_EXPECT_UNIT_VEC3)
		printf("vec3 with a range from -1 to 1");
	else if (expected_code == MRT_PARSER_EXPECT_COLOR)
		printf("a RGB color");
	else if (expected_code == MRT_PARSER_EXPECT_PERCENTAGE)
		printf("vec3 with a range from 0 to 1");
	else if (expected_code == MRT_PARSER_EXPECT_END_OF_LINE)
		printf("end of line");
	else if (expected_code == MRT_PARSER_EXPECT_END_OF_LINE_OR_SPACE)
		printf("end of line or space");
}
