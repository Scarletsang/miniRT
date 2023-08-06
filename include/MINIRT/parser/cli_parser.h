/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:04:32 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 18:03:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_PARSER_H
# define CLI_PARSER_H

# include "MINIRT/scene.h"
# include "MINIRT/renderer.h"
# include <stdlib.h>

struct s_mrt_scene	mrt_scene_from_file(char *file_name);


#endif