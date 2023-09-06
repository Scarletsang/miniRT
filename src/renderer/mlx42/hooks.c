/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:38:18 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 13:14:45 by htsang           ###   ########.fr       */
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

void	mrt_mlx42_mouse_hook(mouse_key_t button, action_t action, \
modifier_key_t mods, struct s_mrt_renderer_mlx42 *renderer)
{
	int32_t	x;
	int32_t	y;

	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		mlx_get_mouse_pos(renderer->mlx, &x, &y);
		renderer->renderer_data.config.debug_level = DEBUG_LEVEL_PRINT;
		mrt_render_color_at(&renderer->renderer_data, x, y);
		renderer->renderer_data.config.debug_level = DEBUG_LEVEL_NONE;
	}
}

void	mrt_mlx42_loop_hook(struct s_mrt_renderer_mlx42 *renderer)
{
	t_mrt_point3d	*origin;

	if (mrt_mlx42_control_as_int(renderer->control) == 0)
		return ;
	origin = &mrt_world_get_camera(\
		renderer->renderer_data.world)->scene->origin;
	if (renderer->control.forward)
		origin->z -= 0.75;
	if (renderer->control.backward)
		origin->z += 0.75;
	if (renderer->control.left)
		origin->x += 0.75;
	if (renderer->control.right)
		origin->x -= 0.75;
	if (renderer->control.upward)
		origin->y += 0.75;
	if (renderer->control.downward)
		origin->y -= 0.75;
	mrt_camera_refresh(mrt_world_get_camera(\
		renderer->renderer_data.world));
	mrt_renderer_mlx42_render(renderer);
}
