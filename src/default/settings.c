/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:27:39 by htsang            #+#    #+#             */
/*   Updated: 2023/08/15 12:49:44 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"

struct s_mrt_renderer_config	mrt_default_renderer_config(void)
{
	return ((struct s_mrt_renderer_config){
		.anti_aliasing_sample_count = 1,
		.maximum_recursion_depth = 5,
		.maximum_world_distance = 1000000.0,
		.thread_count = 1,
		.ppm_output_file_name = "output.ppm"
	});
}

struct s_mrt	mrt_default(void)
{
	return ((struct s_mrt){
		.renderer = mrt_renderer_mlx42,
		.renderer_config = mrt_default_renderer_config(),
		.world = (struct s_mrt_world){}
	});
}

struct s_mrt_world_options	mrt_default_world_options(void)
{
	return ((struct s_mrt_world_options){
		.camera_focal_length = 1.0,
		.camera_image = mrt_image_fixed_width(16.0 / 9.0, 400)
	});
}
