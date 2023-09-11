/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:45:26 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:58:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"
#include "LIBFT/ctype.h"

struct s_ft_parser_atom	mrt_parser_atom_with_trace(\
struct s_ft_parser_atom input, enum e_mrt_parser_expected_code expected_code, \
enum e_mrt_parser_error_code error_code)
{
	ft_parser_atom_add_error_trace(input, expected_code, error_code);
	return (ft_parser_atom_validity_set(input, false));
}

static struct s_ft_parser_atom	mrt_scene_parser_ignore_upper_case_string(\
struct s_ft_parser_atom input, union u_ft_tobject identifier)
{
	struct s_ft_parser_atom	result;
	char					*c;
	size_t					i;

	i = 0;
	result = input;
	while (identifier.as_str[i])
	{
		c = ft_parser_peek(result.string, 0);
		if (*c != ft_toupper(identifier.as_str[i]))
			return (ft_parser_atom_validity_set(input, false));
		result.string = ft_parser_advance(result.string, 1);
		i++;
	}
	return (ft_parser_atom_validity_set(result, true));
}

/**
 * @brief If the identifier is uppercase, it expect uppercase string. Otherwise,
 * it accepts both uppercase and lowercase string.
*/
t_mrt_scene_parser_atom	mrt_scene_parser_identifier(\
t_mrt_scene_parser_atom input, union u_ft_tobject identifier)
{
	t_mrt_scene_parser_atom	result;
	char					first_character;

	first_character = *ft_parser_peek(input.string, 0);
	if (ft_isupper(identifier.as_str[0]))
		result = ft_parser_ignore_string(input, identifier);
	else
		result = ft_combinator_or((struct s_ft_parser_entity[2]){\
			ft_parser_entity(ft_parser_ignore_string, identifier), \
			ft_parser_entity(mrt_scene_parser_ignore_upper_case_string, \
				identifier), \
		}, 2, input, ft_tobject_empty());
	if (!result.is_valid)
	{
		ft_parser_atom_add_error_trace(result, \
			MRT_PARSER_EXPECT_IDENTIFIER, \
			MRT_PARSER_ERROR_INVALID_IDENTIFIER);
		return (ft_parser_atom_validity_set(input, false));
	}
	*(bool *) result.payload.as_ptr = ft_isupper(first_character);
	return (result);
}

t_mrt_scene_parser_atom	mrt_scene_parser_line_ends(\
t_mrt_scene_parser_atom input, union u_ft_tobject option)
{
	t_mrt_scene_parser_atom	result;

	(void) option;
	result = ft_parser_atom_validity_set(input, ft_parser_atom_is_end(input));
	if (!ft_parser_atom_is_end(result))
	{
		ft_parser_atom_add_error_trace(result, MRT_PARSER_EXPECT_END_OF_LINE, \
			MRT_PARSER_ERROR_EXTRA_ARGUMENT);
		return (ft_parser_atom_validity_set(input, false));
	}
	return (result);
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
		if (i == 0)
			result = ft_parser_atom_validity_set(result, true);
		else if (!result.is_valid)
			return (mrt_parser_atom_with_trace(input, \
				MRT_PARSER_EXPECT_END_OF_LINE_OR_SPACE, \
				MRT_PARSER_ERROR_INVALID_SYNTAX));
		entity = ft_decorator_entity(\
			&ft_decorator_struct_field, entities + i, ft_tobject_empty());
		result = ft_parser_entity_evaluate(&entity, result);
		if (!result.is_valid)
			return (ft_parser_atom_validity_set(input, false));
		i++;
	}
	return (ft_parser_atom_validity_set(result, true));
}
