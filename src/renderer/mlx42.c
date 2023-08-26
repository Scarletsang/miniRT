/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:29:23 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 21:47:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/world.h"
#include "MINIRT/ray.h"
#include <MLX42/MLX42.h>
#include <stdlib.h>

static int32_t	mrt_renderer_mlx42_pixel(t_mrt_color color)
{
	return (((int32_t) color.x) << 24 | \
			((int32_t) color.y) << 16 | \
			((int32_t) color.z) << 8 | 0xFF);
}

int	mrt_renderer_mlx42_render(struct s_mrt_world *world, \
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
				mrt_world_get_camera(world)->scene->origin, \
				mrt_pixel_to_direction_from_camera(\
					mrt_world_get_camera(world), x, y));
			mlx_put_pixel(image, x, y, \
				mrt_renderer_mlx42_pixel(mrt_ray_color(&ray, world)));
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

static int	mrt_renderer_mlx42_init(struct s_mrt_renderer_mlx42 *renderer, \
struct s_mrt_world *world, struct s_mrt_renderer_config *config)
{
	*renderer = (struct s_mrt_renderer_mlx42){\
		.world = world, \
		.config = config, \
		.mlx = mlx_init(\
			mrt_world_get_camera(world)->screen.width, \
			mrt_world_get_camera(world)->screen.height, \
			"miniRT", false), \
		.image = NULL, \
		.control = (struct s_mrt_mlx42_control){0} \
	};
	if (renderer->mlx == NULL)
		return (EXIT_FAILURE);
	renderer->image = mlx_new_image(renderer->mlx, \
		mrt_world_get_camera(world)->screen.width, \
		mrt_world_get_camera(world)->screen.height);
	if (renderer->image == NULL)
	{
		mlx_terminate(renderer->mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	mrt_renderer_mlx42(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config)
{
	struct s_mrt_renderer_mlx42	renderer;

	if (mrt_renderer_mlx42_init(&renderer, world, config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mlx_image_to_window(renderer.mlx, renderer.image, 0, 0);
	mrt_renderer_mlx42_render(world, config, renderer.image);
	mlx_key_hook(renderer.mlx, \
		(mlx_keyfunc) mrt_mlx42_key_hook, &renderer);
	mlx_loop_hook(renderer.mlx, \
		(void (*)(void *)) mrt_mlx42_loop_hook, &renderer);
	mlx_loop(renderer.mlx);
	mlx_terminate(renderer.mlx);
	return (EXIT_SUCCESS);
}
