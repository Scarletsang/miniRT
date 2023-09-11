/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:44:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 12:47:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/general_parser.h"
#include "MINIRT/unit/vec3.h"

static struct s_ft_parser_atom	mrt_parser_vec3_field(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject vec3_type)
{
	struct s_ft_parser_atom			result;
	struct s_ft_parser_struct		*parser;

	result = ft_parser_entity_evaluate(&entity, input);
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	parser = input.payload.as_ptr;
	if (parser->current >= parser->fields.size)
		return (ft_parser_atom_validity_set(input, false));
	else if (vec3_type.as_int == VEC3_FLOAT)
		*(double *) ft_parser_struct_current(parser) = \
			result.payload.as_float;
	else if (vec3_type.as_int == VEC3_UINT)
		*(double *) ft_parser_struct_current(parser) = \
			(double) result.payload.as_uint;
	parser->current++;
	return (ft_parser_atom_chain(input, input.payload, result.string));
}

static struct s_ft_parser_atom	mrt_parser_vec3(\
struct s_ft_parser_entity entity, struct s_ft_parser_atom input, \
union u_ft_tobject vec3_type)
{
	t_mrt_vec3					vec3;
	struct s_ft_parser_struct	parser;
	struct s_ft_parser_atom		result;

	parser = ft_parser_struct_init((void *[3]){&vec3.x, &vec3.y, &vec3.z}, 3);
	result = ft_combinator_and((struct s_ft_parser_entity[5]){\
		ft_decorator_entity(&mrt_parser_vec3_field, \
			(struct s_ft_parser_entity[1]){entity}, vec3_type), \
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_decorator_entity(&mrt_parser_vec3_field, \
			(struct s_ft_parser_entity[1]){entity}, vec3_type), \
		ft_parser_entity(&ft_parser_ignore, ft_tobject_str(",")), \
		ft_decorator_entity(&mrt_parser_vec3_field, \
			(struct s_ft_parser_entity[1]){entity}, vec3_type),
		}, 5, ft_parser_atom_payload_set(input, ft_tobject_ptr(&parser)), \
			ft_tobject_empty());
	if (result.is_valid)
		*((t_mrt_vec3 *) input.payload.as_ptr) = vec3;
	return (ft_parser_atom_payload_set(result, input.payload));
}

struct s_ft_parser_atom	mrt_parser_vec3_float(\
struct s_ft_parser_atom input, union u_ft_tobject range_object)
{
	return (mrt_parser_vec3(ft_parser_entity(&mrt_parser_float, range_object), \
		input, ft_tobject_int(VEC3_FLOAT)));
}

struct s_ft_parser_atom	mrt_parser_vec3_uint(\
struct s_ft_parser_atom input, union u_ft_tobject range_object)
{
	return (mrt_parser_vec3(ft_parser_entity(&mrt_parser_uint, range_object), \
		input, ft_tobject_int(VEC3_UINT)));
}
