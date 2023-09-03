/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:38:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 15:53:04 by htsang           ###   ########.fr       */
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
	if (mrt_mlx42_control_switch(keydata, MLX_KEY_W, MLX_KEY_UP))
		renderer->control.forward ^= 1;
	if (mrt_mlx42_control_switch(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		renderer->control.backward ^= 1;
	if (mrt_mlx42_control_switch(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		renderer->control.left ^= 1;
	if (mrt_mlx42_control_switch(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		renderer->control.right ^= 1;
	if (keydata.key == MLX_KEY_SPACE && keydata.action != MLX_REPEAT)
	{
		if (keydata.modifier & MLX_SHIFT)
			renderer->control.upward ^= 1;
		else
			renderer->control.downward ^= 1;
	}
}

void	mrt_mlx42_loop_hook(struct s_mrt_renderer_mlx42 *renderer)
{
	if (mrt_mlx42_control_as_int(renderer->control) == 0)
		return ;
	if (renderer->control.forward)
		mrt_world_get_camera(renderer->world)->scene->origin.z -= 0.05;
	if (renderer->control.backward)
		mrt_world_get_camera(renderer->world)->scene->origin.z += 0.05;
	if (renderer->control.left)
		mrt_world_get_camera(renderer->world)->scene->origin.x += 0.05;
	if (renderer->control.right)
		mrt_world_get_camera(renderer->world)->scene->origin.x -= 0.05;
	if (renderer->control.upward)
		mrt_world_get_camera(renderer->world)->scene->origin.y += 0.05;
	if (renderer->control.downward)
		mrt_world_get_camera(renderer->world)->scene->origin.y -= 0.05;
	mrt_renderer_mlx42_render(renderer->world, renderer->config, \
		renderer->image);
}
