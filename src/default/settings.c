/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:27:39 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 20:52:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"

struct s_mrt_renderer_config	mrt_default_renderer_config(\
const char *scene_file_name)
{
	return ((struct s_mrt_renderer_config){
		.anti_aliasing_sample_count = 1,
		.maximum_recursion_depth = 5,
		.maximum_world_distance = 1000000.0,
		.thread_count = 1,
		.scene_file_name = scene_file_name,
		.ppm_output_file_name = "output.ppm"
	});
}

struct s_mrt	mrt_default(const char *scene_file_name)
{
	return ((struct s_mrt){
		.renderer = mrt_renderer_ppm,
		.renderer_config = mrt_default_renderer_config(scene_file_name),
		.world = (struct s_mrt_world){}
	});
}

struct s_mrt_world_options	mrt_default_world_options(void)
{
	return ((struct s_mrt_world_options){
		.camera_focal_length = 1.0,
		.camera_image = mrt_image_fixed_width(30.0 / 9.0, 1600)
	});
}
