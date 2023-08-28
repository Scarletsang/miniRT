/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:20:29 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 16:43:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/renderer.h"
#include "MINIRT/ray.h"
#include "MINIRT/parser/scene_parser.h"

static int	mrt_world_create(struct s_mrt *program, \
struct s_mrt_world_options world_option)
{
	struct s_mrt_scene	scene;

	if (mrt_scene_init(&scene))
		return (EXIT_FAILURE);
	else if (mrt_scene_parse_from_file(&scene, \
		program->renderer_config.scene_file_name) || \
		mrt_world_from_scene(&scene, &program->world, world_option))
	{
		mrt_scene_free(&scene);
		return (EXIT_FAILURE);
	}
	mrt_scene_free(&scene);
	return (EXIT_SUCCESS);
}

int	main(int argc, const char **argv)
{
	struct s_mrt				mrt;
	struct s_mrt_world_options	world_options;

	if (argc != 2)
		return (EXIT_FAILURE);
	mrt = mrt_default(argv[1]);
	world_options = mrt_default_world_options();
	if (mrt_world_init(&mrt.world))
		return (EXIT_FAILURE);
	else if (mrt_world_create(&mrt, world_options) || \
		mrt.renderer(&mrt.world, &mrt.renderer_config))
	{
		mrt_world_free(&mrt.world);
		return (EXIT_FAILURE);
	}
	mrt_world_free(&mrt.world);
	return (EXIT_SUCCESS);
}
