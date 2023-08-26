/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:38:18 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 21:41:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/renderer.h"
#include <MLX42/MLX42.h>
#include <stdio.h>

void	mrt_mlx42_key_hook(mlx_key_data_t keydata, \
struct s_mrt_renderer_mlx42 *renderer)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(renderer->mlx);
		return ;
	}
	if (keydata.key == MLX_KEY_UP && keydata.action != MLX_REPEAT)
		renderer->control.up_key ^= 1;
	if (keydata.key == MLX_KEY_DOWN && keydata.action != MLX_REPEAT)
		renderer->control.down_key ^= 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action != MLX_REPEAT)
		renderer->control.left_key ^= 1;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action != MLX_REPEAT)
		renderer->control.right_key ^= 1;
}

void	mrt_mlx42_loop_hook(struct s_mrt_renderer_mlx42 *renderer)
{
	if (mrt_mlx42_control_as_int(renderer->control) == 0)
		return ;
	if (renderer->control.up_key)
		mrt_world_get_camera(renderer->world)->scene->origin.y -= 0.05;
	if (renderer->control.down_key)
		mrt_world_get_camera(renderer->world)->scene->origin.y += 0.05;
	if (renderer->control.left_key)
		mrt_world_get_camera(renderer->world)->scene->origin.x += 0.05;
	if (renderer->control.right_key)
		mrt_world_get_camera(renderer->world)->scene->origin.x -= 0.05;
	mrt_renderer_mlx42_render(renderer->world, renderer->config, \
		renderer->image);
}
