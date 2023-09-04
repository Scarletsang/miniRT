/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:07:04 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 22:11:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "LIBFT/parser.h"
#include "LIBFT/iostream.h"
#include <fcntl.h>
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

static int	mrt_scene_parser_cleanup(struct s_ft_iostream *iostream, \
int fd, int return_value)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (fd != -1)
	{
		if (close(fd) == -1)
			exit_code = EXIT_FAILURE;
	}
	ft_iostream_free(iostream);
	if (exit_code == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (return_value);
}

static int	mrt_scene_parser_from_iostream(struct s_mrt_scene *scene, \
struct s_ft_iostream *iostream)
{
	t_mrt_scene_parser_atom	atom;

	if (!ft_slice_is_empty(ft_iostream_to_slice(iostream)))
	{
		atom = mrt_scene_parser_entry(\
			ft_parser_atom(ft_tobject_ptr(scene), \
			ft_iostream_to_slice(iostream)), ft_tobject_empty());
		if (!atom.is_valid || !ft_parser_atom_is_end(atom))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	mrt_scene_parse_from_file(struct s_mrt_scene *scene, const char *file_path)
{
	struct s_ft_iostream	iostream;
	int						fd;

	fd = open(file_path, O_RDONLY, 0644);
	if (fd == -1)
		return (EXIT_FAILURE);
	if (ft_iostream_init(&iostream))
		return (close(fd), EXIT_FAILURE);
	while (!ft_iostream_read_until_delimiter(&iostream, fd, \
		ft_str_from_cstring("\n")))
	{
		if (mrt_scene_parser_from_iostream(scene, &iostream))
			return (mrt_scene_parser_cleanup(&iostream, fd, EXIT_FAILURE));
		ft_iostream_reset(&iostream);
	}
	if (mrt_scene_parser_from_iostream(scene, &iostream) || \
		!mrt_scene_is_valid(scene))
		return (mrt_scene_parser_cleanup(&iostream, fd, EXIT_FAILURE));
	return (mrt_scene_parser_cleanup(&iostream, fd, EXIT_SUCCESS));
}
