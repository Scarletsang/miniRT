/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:15:36 by htsang            #+#    #+#             */
/*   Updated: 2023/08/10 18:09:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"

t_mrt_unit_parser_atom	mrt_scene_parser_point3d(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object)
{
	(void) range_object;
	return (input);
}

t_mrt_unit_parser_atom	mrt_scene_parser_direction3d(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object)
{
	(void) range_object;
	return (input);
}

t_mrt_unit_parser_atom	mrt_scene_parser_degrees(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object)
{
	(void) range_object;
	return (input);
}

t_mrt_unit_parser_atom	mrt_scene_parser_color(\
t_mrt_unit_parser_atom input, union u_ft_tobject option)
{
	t_mrt_range	range;

	(void) option;
	range = mrt_range(0.0, 255.0);
	return (mrt_parser_vec3_uint(input, ft_tobject_ptr(&range)));
}
