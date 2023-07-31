/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:43:04 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 16:17:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "MINIRT/unit.h"
# include "MINIRT/scene.h"
# include "LIBFT/vector.h"
# include "LIBFT/slice.h"

struct s_mrt_scene_parser
{
	t_ft_str			line;
	size_t				cursor;
	struct s_mrt_scene	scene;
};

int		mrt_scene_parser_init(struct s_mrt_scene_parser *parser);

void	mrt_scene_parser_free(struct s_mrt_scene_parser *parser);

//////////////////////////////////////////
////////////   entry parser   ////////////
//////////////////////////////////////////


enum s_mrt_scene_entry_identifier	mrt_scene_parser_identifier(\
struct s_mrt_scene_parser *parser);

int									mrt_scene_parser_sphere(\
struct s_mrt_scene_parser *parser);

int									mrt_scene_parser_plane(\
struct s_mrt_scene_parser *parser);

int									mrt_scene_parser_cylinder(\
struct s_mrt_scene_parser *parser);

int									mrt_scene_parser_light_ambient(\
struct s_mrt_scene_parser *parser);

int									mrt_scene_parser_light_point(\
struct s_mrt_scene_parser *parser);

int									mrt_scene_parser_camera(\
struct s_mrt_scene_parser *parser);


/////////////////////////////////////////
////////////   unit parser   ////////////
/////////////////////////////////////////

int									mrt_scene_parser_point3d(\
struct s_mrt_scene_parser *parser, t_mrt_range range);

int									mrt_scene_parser_direction3d(\
struct s_mrt_scene_parser *parser, t_mrt_range range);

int									mrt_scene_parser_ratio(\
struct s_mrt_scene_parser *parser, t_mrt_range range);

int									mrt_scene_parser_degrees(\
struct s_mrt_scene_parser *parser, t_mrt_range range);

int									mrt_scene_parser_color(\
struct s_mrt_scene_parser *parser);

///////////////////////////////////
////////////   lexer   ////////////
///////////////////////////////////

int									mrt_scene_parser_ignore(\
struct s_mrt_scene_parser *parser, t_ft_str set);

int									mrt_scene_parser_double(\
struct s_mrt_scene_parser *parser, t_mrt_range range);

int									mrt_scene_parser_comma(\
struct s_mrt_scene_parser *parser, t_ft_str set);

#endif