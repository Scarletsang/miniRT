/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:13:06 by htsang            #+#    #+#             */
/*   Updated: 2023/08/09 09:16:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_PARSER_H
# define NUMBER_PARSER_H

# include "LIBFT/parser.h"

struct s_ft_parser_atom	mrt_parser_float(\
struct s_ft_parser_atom input, union u_ft_tobject range_object);

struct s_ft_parser_atom	mrt_parser_uint(\
struct s_ft_parser_atom input, union u_ft_tobject range_object);

#endif