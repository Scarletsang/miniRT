/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:13:06 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:59:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_PARSER_H
# define GENERAL_PARSER_H

# include "LIBFT/parser.h"

///////////////////////////////////////////
////////////   error printer   ////////////
///////////////////////////////////////////

enum	e_mrt_parser_error_code
{
	MRT_PARSER_ERROR_INVALID_IDENTIFIER,
	MRT_PARSER_ERROR_UNIQUE_IDENTIFIER_REPEATED,
	MRT_PARSER_ERROR_OUT_OF_RANGE,
	MRT_PARSER_ERROR_EXTRA_ARGUMENT,
	MRT_PARSER_ERROR_INVALID_SYNTAX
};

enum	e_mrt_parser_expected_code
{
	MRT_PARSER_EXPECT_IDENTIFIER,
	MRT_PARSER_EXPECT_FLOAT,
	MRT_PARSER_EXPECT_UINT,
	MRT_PARSER_EXPECT_VEC3,
	MRT_PARSER_EXPECT_UNIT_VEC3,
	MRT_PARSER_EXPECT_COLOR,
	MRT_PARSER_EXPECT_PERCENTAGE,
	MRT_PARSER_EXPECT_END_OF_LINE,
	MRT_PARSER_EXPECT_END_OF_LINE_OR_SPACE,
};

void						mrt_syntax_expected_printer(int expected_code);

void						mrt_syntax_error_printer(int error_code);

enum	e_mrt_parser_vec3_option_type
{
	VEC3_FLOAT,
	VEC3_UINT,
};

struct s_ft_parser_atom		mrt_parser_float(\
struct s_ft_parser_atom input, union u_ft_tobject range_object);

struct s_ft_parser_atom		mrt_parser_uint(\
struct s_ft_parser_atom input, union u_ft_tobject range_object);

struct s_ft_parser_atom		mrt_parser_vec3_float(\
struct s_ft_parser_atom input, union u_ft_tobject range_object);

struct s_ft_parser_atom		mrt_parser_vec3_uint(\
struct s_ft_parser_atom input, union u_ft_tobject range_object);

struct s_ft_parser_atom		mrt_parser_atom_with_trace(\
struct s_ft_parser_atom input, enum e_mrt_parser_expected_code expected_code, \
enum e_mrt_parser_error_code error_code);

#endif