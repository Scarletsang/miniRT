/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:01:58 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 10:02:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"
#include "MINIRT/error.h"
#include "LIBFT/parser.h"
#include "LIBFT/iostream.h"
#include <stdlib.h>

static inline t_mrt_scene_parser_atom	mrt_scene_parser_entry(\
t_mrt_scene_parser_atom input, union u_ft_tobject option)
{
	return (ft_combinator_or((struct s_ft_parser_entity[7]){\
		ft_parser_entity(&mrt_scene_parser_sphere, option), \
		ft_parser_entity(&mrt_scene_parser_plane, option), \
		ft_parser_entity(&mrt_scene_parser_cylinder, option), \
		ft_parser_entity(&mrt_scene_parser_light_ambient, option), \
		ft_parser_entity(&mrt_scene_parser_light_point, option), \
		ft_parser_entity(&mrt_scene_parser_camera, option), \
		ft_parser_entity(&ft_parser_ignore_multiple, ft_tobject_str(" \t\n")) \
	}, 7, input, ft_tobject_empty()));
}

static int	mrt_scene_parser_line(struct s_mrt_scene *scene, \
struct s_mrt_scene_parser *parser)
{
	t_mrt_scene_parser_atom	atom;
	t_ft_str				line;

	line = ft_iostream_to_slice(&parser->iostream);
	if (!ft_slice_is_empty(line))
	{
		ft_error_traces_new_line(&parser->traces, line);
		atom = mrt_scene_parser_entry(\
			ft_parser_atom_with_trace(ft_tobject_ptr(scene), \
				line, &parser->traces), ft_tobject_empty());
		if (!atom.is_valid)
			return (EXIT_FAILURE);
		else if (!ft_parser_atom_is_end(atom))
		{
			ft_parser_atom_add_error_trace(atom, \
				MRT_PARSER_EXPECT_END_OF_LINE, \
				MRT_PARSER_ERROR_EXTRA_ARGUMENT);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	mrt_scene_parse_from_file(struct s_mrt_scene *scene, const char *file_path)
{
	struct s_mrt_scene_parser	parser;

	if (mrt_scene_parser_init(&parser, file_path))
		return (EXIT_FAILURE);
	while (!ft_iostream_read_until_delimiter(&parser.iostream, parser.fd, \
		ft_str_from_cstring("\n")))
	{
		if (mrt_scene_parser_line(scene, &parser))
		{
			ft_error_traces_print(&parser.traces);
			return (mrt_scene_parser_free(&parser), EXIT_FAILURE);
		}
		ft_iostream_reset(&parser.iostream);
	}
	if (mrt_scene_parser_line(scene, &parser))
	{
		ft_error_traces_print(&parser.traces);
		return (mrt_scene_parser_free(&parser), EXIT_FAILURE);
	}
	return (mrt_scene_parser_free(&parser), EXIT_SUCCESS);
}
