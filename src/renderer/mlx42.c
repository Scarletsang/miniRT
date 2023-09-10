/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:29:23 by htsang            #+#    #+#             */
/*   Updated: 2023/09/09 08:56:58 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include "MINIRT/renderer.h"
#include <MLX42/MLX42.h>
#include <stdlib.h>

static int32_t	mrt_renderer_mlx42_pixel(t_mrt_color color)
{
	return (((int32_t) color.x) << 24 | \
			((int32_t) color.y) << 16 | \
			((int32_t) color.z) << 8 | 0xFF);
}

int	mrt_renderer_mlx42_render(struct s_mrt_renderer_mlx42 *renderer)
{
	struct s_mrt_camera	*camera;
	int					x;
	int					y;

	camera = mrt_world_get_camera(renderer->renderer_data.world);
	y = 0;
	while (y < camera->screen.height)
	{
		x = 0;
		while (x < camera->screen.width)
		{
			mlx_put_pixel(renderer->image, x, y, mrt_renderer_mlx42_pixel(\
				mrt_render_color_at(&renderer->renderer_data, x, y)));
			x++;
		}
		y++;
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
	mrt_renderer_mlx42_render(&renderer);
	mlx_key_hook(renderer.mlx, \
		(mlx_keyfunc) mrt_mlx42_key_hook, &renderer);
	mlx_loop_hook(renderer.mlx, \
		(void (*)(void *)) mrt_mlx42_loop_hook, &renderer);
	mlx_mouse_hook(renderer.mlx, \
		(mlx_mousefunc) mrt_mlx42_mouse_hook, &renderer);
	mlx_loop(renderer.mlx);
	mrt_renderer_data_free(&renderer.renderer_data);
	mlx_terminate(renderer.mlx);
	return (EXIT_SUCCESS);
}
