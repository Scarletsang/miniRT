/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:14:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 04:36:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/world.h"
#include "LIBFT/printf.h"
#include <stdlib.h>

static void	mrt_renderer_ppm_color(t_mrt_color pixel_color)
{
	ft_printf("%d %d %d\n", \
		(int)(pixel_color.x), \
		(int)(pixel_color.y), \
		(int)(pixel_color.z));
}

static void	mrt_renderer_ppm_header(struct s_mrt_image *image)
{
	ft_printf("P3\n%d %d\n255\n", image->width, image->height);
}

int	mrt_renderer_ppm(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config)
{
	struct s_mrt_renderer_ppm	renderer;
	int							x;
	int							y;

	if (mrt_renderer_ppm_init(&renderer, world, config))
		return (EXIT_FAILURE);
	mrt_renderer_ppm_header(&(mrt_world_get_camera(world)->screen));
	y = 0;
	while (y < mrt_world_get_camera(world)->screen.height)
	{
		x = 0;
		while (x < mrt_world_get_camera(world)->screen.width)
		{
			mrt_renderer_ppm_color(\
				mrt_render_color_at(&renderer.renderer_data, x, y));
			x++;
		}
		y++;
	}
	return (mrt_renderer_ppm_end(&renderer));
}
