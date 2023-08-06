/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:14:47 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 20:41:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"

static void	mrt_renderer_ppm_color(t_mrt_color pixel_color)
{
	
}

static void	mrt_renderer_ppm_header()
{
	
}

int		mrt_renderer_ppm(t_mrt_world_scene	*scene, \
struct s_mrt_renderer_config *config)
{
	int	i;
	int	j;

	j = viewport->height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < viewport->width)
		{
			// create ray
			mrt_world_scene_render_pixel(scene, i, j);
			i++;
		}
		j--;
	}
}
