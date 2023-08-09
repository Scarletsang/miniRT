/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:43:04 by htsang            #+#    #+#             */
/*   Updated: 2023/08/09 09:25:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "MINIRT/unit.h"
# include "MINIRT/scene.h"
# include "LIBFT/vector.h"
# include "LIBFT/slice.h"
# include "LIBFT/parser.h"

typedef struct s_ft_parser_atom	t_mrt_scene_parser_atom;

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

/////////////////////////////////////////
////////////   unit parser   ////////////
/////////////////////////////////////////

typedef struct s_ft_parser_atom	t_mrt_unit_parser_atom;

t_mrt_unit_parser_atom	mrt_scene_parser_point3d(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

t_mrt_unit_parser_atom	mrt_scene_parser_direction3d(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

t_mrt_unit_parser_atom	mrt_scene_parser_degrees(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

t_mrt_unit_parser_atom	mrt_scene_parser_color(\
t_mrt_unit_parser_atom input, union u_ft_tobject range_object);

#endif