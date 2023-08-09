/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:15:36 by htsang            #+#    #+#             */
/*   Updated: 2023/08/09 09:24:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/number_parser.h"

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
t_mrt_unit_parser_atom input, union u_ft_tobject range_object)
{
	t_mrt_unit_parser_atom	output;
	t_mrt_color				color;

	output = mrt_parser_uint(input, range_object);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	color.x = output.payload.as_uint;
	output = ft_parser_and((struct s_ft_parser_entity[2]){\
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_parser_entity(&mrt_parser_uint, range_object) \
	}, 2, input);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	color.y = output.payload.as_uint;
	output = ft_parser_and((struct s_ft_parser_entity[2]){\
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_parser_entity(&mrt_parser_uint, range_object) \
	}, 2, input);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	color.z = output.payload.as_uint;
	*(t_mrt_color *) input.payload.as_ptr = color;
	return (ft_parser_atom(input.payload, output.string));
}
