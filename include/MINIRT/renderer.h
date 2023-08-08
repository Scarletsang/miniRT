/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:00:52 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 12:25:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "MINIRT/unit.h"
# include "MINIRT/world.h"
# include "MINIRT/world/camera.h"
# include <stdbool.h>
# include <stdint.h>

struct s_mrt_renderer_config
{
	unsigned int	anti_aliasing_sample_count;
	unsigned int	maximum_recursion_depth;
	double			maximum_world_distance;
	unsigned int	thread_count;
	const char		*ppm_output_file_name;
};

struct							s_mrt_world;

typedef int						(*t_mrt_renderer)(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

t_mrt_direction3d				mrt_pixel_to_direction_from_camera(\
struct s_mrt_camera *camera, uint32_t x, uint32_t y);

struct s_mrt_renderer_ppm
{
	int	terminal_fd;
	int	file_fd;
};

int								mrt_renderer_ppm(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

int								mrt_renderer_mlx42(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

#endif