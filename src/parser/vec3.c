/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:44:32 by htsang            #+#    #+#             */
/*   Updated: 2023/08/10 13:05:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/general_parser.h"
#include "MINIRT/unit/vec3.h"

struct s_ft_parser_atom	mrt_parser_vec3_float(\
struct s_ft_parser_atom input, union u_ft_tobject range_object)
{
	struct s_ft_parser_atom	output;
	t_mrt_vec3				vec3;

	output = mrt_parser_float(input, range_object);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	vec3.x = output.payload.as_uint;
	output = ft_parser_and((struct s_ft_parser_entity[2]){\
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_parser_entity(&mrt_parser_float, range_object) \
	}, 2, input);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	vec3.y = output.payload.as_uint;
	output = ft_parser_and((struct s_ft_parser_entity[2]){\
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_parser_entity(&mrt_parser_float, range_object) \
	}, 2, input);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	vec3.z = output.payload.as_uint;
	*(t_mrt_vec3 *) input.payload.as_ptr = vec3;
	return (ft_parser_atom(input.payload, output.string));
}

struct s_ft_parser_atom	mrt_parser_vec3_uint(\
struct s_ft_parser_atom input, union u_ft_tobject range_object)
{
	struct s_ft_parser_atom	output;
	t_mrt_vec3				vec3;

	output = mrt_parser_uint(input, range_object);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	vec3.x = output.payload.as_uint;
	output = ft_parser_and((struct s_ft_parser_entity[2]){\
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_parser_entity(&mrt_parser_uint, range_object) \
	}, 2, input);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	vec3.y = output.payload.as_uint;
	output = ft_parser_and((struct s_ft_parser_entity[2]){\
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_parser_entity(&mrt_parser_uint, range_object) \
	}, 2, input);
	if (!ft_parser_atom_is_ok(output))
		return (ft_parser_atom_validity_set(input, false));
	vec3.z = output.payload.as_uint;
	*(t_mrt_vec3 *) input.payload.as_ptr = vec3;
	return (ft_parser_atom(input.payload, output.string));
}
