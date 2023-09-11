/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:43:04 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 09:59:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "MINIRT/unit.h"
# include "MINIRT/scene.h"
# include "LIBFT/vector.h"
# include "LIBFT/slice.h"
# include "LIBFT/parser.h"
# include "LIBFT/iostream.h"

//////////////////////////////////////////
////////////   scene parser   ////////////
//////////////////////////////////////////

struct s_mrt_scene_parser
{
	struct s_ft_iostream		iostream;
	struct s_ft_error_traces	traces;
	int							fd;
};

int						mrt_scene_parser_init(\
struct s_mrt_scene_parser *parser, const char *file_path);

void					mrt_scene_parser_free(\
struct s_mrt_scene_parser *parser);

typedef struct s_ft_parser_atom	t_mrt_scene_parser_atom;

int						mrt_scene_parse_from_file(struct s_mrt_scene *scene, \
const char *file_path);

//////////////////////////////////////////
////////////   entry parser   ////////////
//////////////////////////////////////////

t_mrt_scene_parser_atom	mrt_scene_parser_sphere(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

t_mrt_scene_parser_atom	mrt_scene_parser_plane(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

t_mrt_scene_parser_atom	mrt_scene_parser_cylinder(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

t_mrt_scene_parser_atom	mrt_scene_parser_light_ambient(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

t_mrt_scene_parser_atom	mrt_scene_parser_light_point(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

t_mrt_scene_parser_atom	mrt_scene_parser_camera(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

t_mrt_scene_parser_atom	mrt_scene_parser_identifier(\
t_mrt_scene_parser_atom input, union u_ft_tobject valid_identifiers);

t_mrt_scene_parser_atom	mrt_scene_parser_material(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

/////////////////////////////////////////
////////////   unit parser   ////////////
/////////////////////////////////////////

typedef struct s_ft_parser_atom	t_mrt_unit_parser_atom;

t_mrt_unit_parser_atom	mrt_scene_parser_vec3(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

t_mrt_unit_parser_atom	mrt_scene_parser_float(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

t_mrt_unit_parser_atom	mrt_scene_parser_color(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

/////////////////////////////////////////
////////////   misc parser   ////////////
/////////////////////////////////////////

t_mrt_scene_parser_atom	mrt_scene_parser_line_ends(\
t_mrt_scene_parser_atom input, union u_ft_tobject option);

//////////////////////////////////////////////
////////////   custom decorator   ////////////
//////////////////////////////////////////////

struct s_ft_parser_atom	mrt_combinator_struct_fields(\
struct s_ft_parser_entity *entities, size_t amount, \
struct s_ft_parser_atom input, union u_ft_tobject prefix);

#endif