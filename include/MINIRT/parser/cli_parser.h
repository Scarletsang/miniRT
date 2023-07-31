/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:04:32 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 23:44:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_PARSER_H
# define CLI_PARSER_H

# include "MINIRT/scene.h"
# include "MINIRT/renderer.h"
# include <stdlib.h>

struct s_mrt_cli_parser
{
	const char						**argv;
	size_t							cursor;
	struct s_mrt_scene				scene;
	struct s_mrt_renderer_config	renderer_config;
};

int					mrt_cli_parser_init(struct s_mrt_cli_parser *parser, \
const char **argv);

struct s_mrt_scene	mrt_scene_from_file(char *file_name);



#endif