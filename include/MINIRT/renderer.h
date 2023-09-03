/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:00:52 by htsang            #+#    #+#             */
/*   Updated: 2023/09/03 00:24:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "MINIRT/unit.h"
# include "MINIRT/world.h"
# include "MINIRT/world/camera.h"
# include "MINIRT/memory.h"
# include <stdbool.h>
# include <stdint.h>
# include <MLX42/MLX42.h>

/////////////////////////////////////////////
////////////   renderer config   ////////////
/////////////////////////////////////////////

struct s_mrt_renderer_config
{
	unsigned int	anti_aliasing_sample_count;
	unsigned int	maximum_recursion_depth;
	double			maximum_world_distance;
	unsigned int	thread_count;
	const char		*scene_file_name;
	const char		*ppm_output_file_name;
};

struct				s_mrt_world;

typedef int			(*t_mrt_renderer)(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

struct s_mrt_renderer_cache
{
	t_ft_vector						intersections;
	struct s_mrt_uniform_allocator	allocators;
};

t_mrt_direction3d	mrt_pixel_to_direction_from_camera(\
struct s_mrt_camera *camera, uint32_t x, uint32_t y);

//////////////////////////////////////////
////////////   ppm renderer   ////////////
//////////////////////////////////////////

struct s_mrt_renderer_ppm
{
	int	terminal_fd;
	int	file_fd;
};

int					mrt_renderer_ppm(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

////////////////////////////////////////////
////////////   mlx42 renderer   ////////////
////////////////////////////////////////////

struct s_mrt_mlx42_control
{
	unsigned int	forward : 1;
	unsigned int	backward : 1;
	unsigned int	left : 1;
	unsigned int	right : 1;
	unsigned int	upward : 1;
	unsigned int	downward : 1;
};

bool				mrt_mlx42_control_switch(mlx_key_data_t keydata, \
keys_t key1, keys_t key2);

unsigned int		mrt_mlx42_control_as_int(\
struct s_mrt_mlx42_control control);

struct s_mrt_renderer_mlx42
{
	struct s_mrt_world				*world;
	struct s_mrt_renderer_config	*config;
	mlx_t							*mlx;
	mlx_image_t						*image;
	struct s_mrt_mlx42_control		control;
};

int					mrt_renderer_mlx42(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

int					mrt_renderer_mlx42_render(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config, mlx_image_t *image);

void				mrt_mlx42_key_hook(mlx_key_data_t keydata, \
struct s_mrt_renderer_mlx42 *renderer);

void				mrt_mlx42_loop_hook(\
struct s_mrt_renderer_mlx42 *renderer);

#endif