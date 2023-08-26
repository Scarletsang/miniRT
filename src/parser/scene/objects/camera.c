/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:50:14 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 17:46:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"
#include "MINIRT/scene/s_objects.h"

static t_mrt_scene_parser_atom	mrt_scene_parser_light_point_run(\
t_mrt_scene_parser_atom input)
{
	t_mrt_range	ranges[2];

	ranges[0] = mrt_range(-1.0, 1.0);
	ranges[1] = mrt_range(0.0, 180.0);
	return (mrt_combinator_prefixed_and((struct s_ft_parser_entity[3]){\
		ft_decorator_entity(&ft_decorator_struct_field, \
			(struct s_ft_parser_entity[1]){ft_parser_entity(\
				&mrt_scene_parser_point3d, ft_tobject_ptr(NULL))}, \
			ft_tobject_empty()),
		ft_decorator_entity(&ft_decorator_struct_field, \
			(struct s_ft_parser_entity[1]){ft_parser_entity(\
				&mrt_scene_parser_direction3d, ft_tobject_ptr(&ranges[0]))}, \
			ft_tobject_empty()),
		ft_decorator_entity(&ft_decorator_struct_field, \
			(struct s_ft_parser_entity[1]){ft_parser_entity(\
				&mrt_scene_parser_float, ft_tobject_ptr(&ranges[1]))}, \
			ft_tobject_empty()),
	}, 3, input, ft_tobject_str(" \t")));
}

t_mrt_scene_parser_atom	mrt_scene_parser_camera(\
t_mrt_scene_parser_atom input, union u_ft_tobject option)
{
	struct s_mrt_scene_camera	camera;
	struct s_ft_parser_struct	parser;
	t_mrt_scene_parser_atom		result;
	bool						is_unique;

	(void) option;
	result = mrt_scene_parser_identifier(ft_parser_atom(\
		ft_tobject_ptr(&is_unique), input.string), ft_tobject_str("C"));
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	parser = ft_parser_struct_init(\
		(void *[3]){&camera.origin, &camera.orientation, &camera.fov}, 3);
	result = mrt_scene_parser_light_point_run(ft_parser_atom(\
		ft_tobject_ptr(&parser), result.string));
	if (result.is_valid)
	{
		if (mrt_scene_add_entry((struct s_mrt_scene *) input.payload.as_ptr, \
			mrt_scene_entry(&camera, ENTRY_CAMERA), is_unique))
			return (ft_parser_atom_validity_set(input, false));
	}
	else
		return (ft_parser_atom_validity_set(input, false));
	return (result);
}
