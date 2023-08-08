/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:20:29 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 11:06:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/renderer.h"
#include "MINIRT/ray.h"

static int	mrt_import_scene_default(struct s_mrt_world *world)
{
	struct s_mrt_scene			scene;
	struct s_mrt_world_options	world_option;

	mrt_scene_init(&scene);
	world_option = (struct s_mrt_world_options){
		.camera_focal_length = 1.0,
		.camera_image = mrt_image_default()
	};
	mrt_scene_add_entry(&scene, mrt_scene_camera_default());
	if (mrt_world_from_scene(world, &scene, world_option))
	{
		mrt_scene_free(&scene);
		return (EXIT_FAILURE);
	}
	ft_vector_free(&scene.entries);
	return (EXIT_SUCCESS);
}

int	main(void)
{
	struct s_mrt	mrt;

	mrt = (struct s_mrt){
		.renderer = mrt_renderer_ppm,
		.renderer_config = mrt_renderer_config_default(),
		.world = (struct s_mrt_world){}
	};
	mrt_world_init(&mrt.world);
	if (mrt_import_scene_default(&mrt.world))
	{
		mrt_world_free(&mrt.world);
		return (EXIT_FAILURE);
	}
	mrt.renderer(&mrt.world, &mrt.renderer_config);
	mrt_world_free(&mrt.world);
	return (EXIT_SUCCESS);
}

/*
#include "MINIRT/miniRT.h"
#include <MLX42/MLX42.h>

int	main(int argc, const char **argv)
{
	mlx_t					*mlx;
	mlx_image_t				*image;
	struct s_mrt_settings	settings;

	(void) argc;
	(void) argv;
	settings.width = 800;
	settings.height = 600;
	mlx = mlx_init(settings.width, settings.height, "miniRT", false);
	image = mlx_new_image(mlx, settings.width, settings.height);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
*/