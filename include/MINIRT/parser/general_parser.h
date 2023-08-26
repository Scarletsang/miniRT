/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parser.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:13:06 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 15:21:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_PARSER_H
# define GENERAL_PARSER_H

# include "LIBFT/parser.h"

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

#endif