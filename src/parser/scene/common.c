/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 03:45:26 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 15:30:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "LIBFT/ctype.h"

t_mrt_scene_parser_atom	mrt_scene_parser_identifier(\
t_mrt_scene_parser_atom input, union u_ft_tobject valid_identifiers)
{
	t_mrt_scene_parser_atom	result;
	bool					identifier_requires_unique;

	if (!ft_isalpha(valid_identifiers.as_str[0]))
		return (ft_parser_atom_validity_set(input, false));
	else
		identifier_requires_unique = ft_isupper(valid_identifiers.as_str[0]);
	result = ft_parser_ignore(input, valid_identifiers);
	if (!result.is_valid)
		return (ft_parser_atom_validity_set(input, false));
	*(bool *) input.payload.as_ptr = identifier_requires_unique;
	return (ft_parser_atom(input.payload, result.string));
}

struct s_ft_parser_atom	mrt_combinator_prefixed_and(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject prefix)
{
	struct s_ft_parser_atom		result;
	size_t						i;

	i = 0;
	result = input;
	while ((i < amount) && !ft_parser_atom_is_end(result))
	{
		result = ft_parser_ignore_multiple(result, prefix);
		if (!result.is_valid)
			return (ft_parser_atom_validity_set(input, false));
		result = ft_parser_entity_evaluate(entities + i, result);
		if (!result.is_valid)
			return (ft_parser_atom_validity_set(input, false));
		i++;
	}
	return (ft_parser_atom_validity_set(result, true));
}
