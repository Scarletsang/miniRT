/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:14:00 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 13:45:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include "MINIRT/renderer.h"
#include <MLX42/MLX42.h>
#include <stdlib.h>
#include <float.h>

int	mrt_renderer_mlx42_init(struct s_mrt_renderer_mlx42 *renderer, \
struct s_mrt_world *world, struct s_mrt_renderer_config *config)
{
	*renderer = (struct s_mrt_renderer_mlx42){\
		.renderer_data = (struct s_mrt_renderer_data){0}, \
		.mlx = mlx_init(\
			mrt_world_get_camera(world)->screen.width, \
			mrt_world_get_camera(world)->screen.height, \
			"miniRT", true), \
		.image = NULL, \
		.control = (struct s_mrt_mlx42_control){0}, \
		.last_cursor_position = vec2(DBL_MAX, DBL_MAX) \
	};
	if ((renderer->mlx == NULL) || \
		(mrt_renderer_data_init(&renderer->renderer_data, world, config)))
		return (mrt_renderer_mlx42_free(renderer), EXIT_FAILURE);
	renderer->image = mlx_new_image(renderer->mlx, \
		mrt_world_get_camera(world)->screen.width, \
		mrt_world_get_camera(world)->screen.height);
	if (renderer->image == NULL)
		return (mrt_renderer_mlx42_free(renderer), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	mrt_renderer_mlx42_free(struct s_mrt_renderer_mlx42 *renderer)
{
	mrt_renderer_data_free(&renderer->renderer_data);
	if (renderer->mlx)
		mlx_terminate(renderer->mlx);
}
