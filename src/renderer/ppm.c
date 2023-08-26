/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:14:47 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 20:07:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/world.h"
#include "MINIRT/ray.h"
#include "LIBFT/printf.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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

static int	mrt_renderer_ppm_start(struct s_mrt_renderer_ppm *ppm, \
struct s_mrt_renderer_config *config)
{
	ppm->file_fd = open(config->ppm_output_file_name, \
		O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ppm->file_fd < 0)
		return (EXIT_FAILURE);
	ppm->terminal_fd = dup(STDOUT_FILENO);
	if (ppm->terminal_fd < 0)
		return (EXIT_FAILURE);
	else if (dup2(ppm->file_fd, STDOUT_FILENO) < 0)
	{
		close(ppm->terminal_fd);
		close(ppm->file_fd);
		return (EXIT_FAILURE);
	}
	close(ppm->file_fd);
	return (EXIT_SUCCESS);
}

static int	mrt_renderer_ppm_end(struct s_mrt_renderer_ppm *ppm)
{
	if (dup2(ppm->terminal_fd, STDOUT_FILENO) < 0)
	{
		close(ppm->terminal_fd);
		return (EXIT_FAILURE);
	}
	else if (close(ppm->terminal_fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	mrt_renderer_ppm(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config)
{
	int							x;
	int							y;
	t_mrt_ray					ray;
	struct s_mrt_renderer_ppm	ppm;

	if (mrt_renderer_ppm_start(&ppm, config) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	mrt_renderer_ppm_header(&(mrt_world_get_camera(world)->screen));
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
			mrt_renderer_ppm_color(mrt_ray_color(&ray, world));
			x++;
		}
		y++;
	}
	return (mrt_renderer_ppm_end(&ppm));
}
