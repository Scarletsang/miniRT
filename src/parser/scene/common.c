/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:45:26 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 16:07:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "LIBFT/ctype.h"

static struct s_ft_parser_atom	mrt_scene_parser_ignore_upper_case_string(\
struct s_ft_parser_atom input, union u_ft_tobject string)
{
	struct s_ft_parser_atom	result;
	char					*c;
	size_t					i;

	i = 0;
	result = input;
	while (string.as_str[i])
	{
		c = ft_parser_peek(result.string, 0);
		if (*c != ft_toupper(string.as_str[i]))
			return (ft_parser_atom_validity_set(input, false));
		result.string = ft_parser_advance(result.string, 1);
		i++;
	}
	return (result);
}

/**
 * @brief If the identifier is uppercase, it expect uppercase string. Otherwise,
 * it accepts both uppercase and lowercase string.
*/
t_mrt_scene_parser_atom	mrt_scene_parser_identifier(\
t_mrt_scene_parser_atom input, union u_ft_tobject identifier)
{
	t_mrt_scene_parser_atom	result;

	if (ft_isupper(identifier.as_str[0]))
		result = ft_parser_ignore_string(input, identifier);
	else
		result = ft_combinator_or((struct s_ft_parser_entity[2]){\
			ft_parser_entity(ft_parser_ignore_string, identifier), \
			ft_parser_entity(mrt_scene_parser_ignore_upper_case_string, \
				identifier), \
		}, 2, input, ft_tobject_empty());
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	*(bool *) input.payload.as_ptr = ft_isupper(identifier.as_str[0]);
	return (ft_parser_atom(input.payload, result.string));
}

struct s_ft_parser_atom	mrt_combinator_struct_fields(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject prefix)
{
	struct s_ft_parser_atom		result;
	struct s_ft_parser_entity	entity;
	size_t						i;

	i = 0;
	result = input;
	while ((i < amount) && !ft_parser_atom_is_end(result))
	{
		result = ft_parser_ignore_multiple(result, prefix);
		if ((i != 0) && !result.is_valid)
			return (ft_parser_atom_validity_set(input, false));
		entity = ft_decorator_entity(\
			&ft_decorator_struct_field, entities + i, ft_tobject_empty());
		result = ft_parser_entity_evaluate(&entity, result);
		if (!result.is_valid)
			return (ft_parser_atom_validity_set(input, false));
		i++;
	}
	return (ft_parser_atom_validity_set(result, true));
}
