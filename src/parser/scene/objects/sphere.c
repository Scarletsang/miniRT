/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:50:14 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 15:49:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"
#include "MINIRT/scene/s_objects.h"

static t_mrt_scene_parser_atom	mrt_scene_parser_sphere_parameters(\
t_mrt_scene_parser_atom input, union u_ft_tobject delimiter)
{
	return (mrt_combinator_struct_fields((struct s_ft_parser_entity[3]){\
		ft_parser_entity(&mrt_scene_parser_vec3, ft_tobject_ptr(NULL)), \
		ft_parser_entity(&mrt_scene_parser_float, ft_tobject_ptr(NULL)), \
		ft_parser_entity(&mrt_scene_parser_material, ft_tobject_ptr(NULL)) \
	}, 3, input, delimiter));
}

t_mrt_scene_parser_atom	mrt_scene_parser_sphere(\
t_mrt_scene_parser_atom input, union u_ft_tobject option)
{
	struct s_mrt_scene_sphere	sphere;
	struct s_ft_parser_struct	parser;
	t_mrt_scene_parser_atom		result;
	bool						is_unique;

	(void) option;
	result = mrt_scene_parser_identifier(ft_parser_atom_payload_set(\
		input, ft_tobject_ptr(&is_unique)), ft_tobject_str("sp"));
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	parser = ft_parser_struct_init(\
		(void *[3]){&sphere.center, &sphere.diameter, &sphere.material}, 3);
	result = mrt_scene_parser_sphere_parameters(ft_parser_atom_payload_set(\
		result, ft_tobject_ptr(&parser)), ft_tobject_str(" \t"));
	if (result.is_valid)
	{
		if (mrt_scene_add_entry((struct s_mrt_scene *) input.payload.as_ptr, \
			mrt_scene_entry(&sphere, ENTRY_SPHERE), is_unique))
			return (ft_parser_atom_validity_set(input, false));
		return (result);
	}
	else
		return (ft_parser_atom_validity_set(input, false));
}
