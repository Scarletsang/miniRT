/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:29:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 12:11:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/world.h"
#include "MINIRT/ray.h"
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <stdio.h>

static int32_t	mrt_renderer_mlx42_pixel(t_mrt_color color)
{
	return (((int32_t) color.x) << 24 | \
			((int32_t) color.y) << 16 | \
			((int32_t) color.z) << 8 | 0xFF);
}

static int	mrt_renderer_mlx42_render(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config, mlx_image_t *image)
{
	int			x;
	int			y;
	t_mrt_ray	ray;

	(void) config;
	y = 0;
	while (y < mrt_world_get_camera(world)->screen.height)
	{
		x = 0;
		while (x < mrt_world_get_camera(world)->screen.width)
		{
			ray = mrt_ray(\
				mrt_world_get_camera(world)->world->origin, \
				mrt_pixel_to_direction_from_camera(\
					mrt_world_get_camera(world), x, y));
			mlx_put_pixel(image, x, y, \
				mrt_renderer_mlx42_pixel(mrt_ray_color(&ray)));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	mrt_renderer_mlx42(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	(void) config;
	mlx = mlx_init(\
		mrt_world_get_camera(world)->screen.width, \
		mrt_world_get_camera(world)->screen.height, \
		"miniRT", false);
	image = mlx_new_image(mlx, \
		mrt_world_get_camera(world)->screen.width, \
		mrt_world_get_camera(world)->screen.height);
	mlx_image_to_window(mlx, image, 0, 0);
	mrt_renderer_mlx42_render(world, config, image);
	printf("Render complete\n");
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
