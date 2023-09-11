/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 13:12:50 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 10:56:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"
#include "MINIRT/scene/s_objects.h"

static t_mrt_scene_parser_atom	mrt_scene_parser_material_run(\
t_mrt_scene_parser_atom input)
{
	t_mrt_range					range[2];
	struct s_ft_parser_entity	entities[2];

	range[0] = mrt_range(0.0, 1.0);
	range[1] = mrt_range(0.0, 200.0);
	entities[0] = ft_parser_entity(&mrt_scene_parser_float, \
		ft_tobject_ptr(&range[0]));
	entities[1] = ft_parser_entity(&mrt_scene_parser_float, \
		ft_tobject_ptr(&range[1]));
	return (mrt_combinator_struct_fields((struct s_ft_parser_entity[4]){\
		ft_parser_entity(&mrt_scene_parser_color, ft_tobject_ptr(NULL)), \
		ft_decorator_entity(&ft_decorator_optional, &entities[0], \
			ft_tobject_ptr(NULL)), \
		ft_decorator_entity(&ft_decorator_optional, &entities[0], \
			ft_tobject_ptr(NULL)), \
		ft_decorator_entity(&ft_decorator_optional, &entities[1], \
			ft_tobject_ptr(NULL)) \
	}, 4, input, ft_tobject_str(" \t")));
}

t_mrt_scene_parser_atom	mrt_scene_parser_material(\
t_mrt_scene_parser_atom input, union u_ft_tobject option)
{
	struct s_mrt_material		material;
	struct s_ft_parser_struct	parser;
	t_mrt_scene_parser_atom		result;

	(void) option;
	mrt_material_default(&material);
	parser = ft_parser_struct_init(\
		(void *[4]){&material.color, &material.diffuse, \
		&material.specular, &material.shininess}, 4);
	result = mrt_scene_parser_material_run(ft_parser_atom_payload_set(\
		input, ft_tobject_ptr(&parser)));
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	*(struct s_mrt_material *) input.payload.as_ptr = material;
	return (ft_parser_atom_chain(input, input.payload, result.string));
}
