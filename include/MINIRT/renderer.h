/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:00:52 by htsang            #+#    #+#             */
/*   Updated: 2023/09/06 06:06:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "MINIRT/unit.h"
# include "MINIRT/world.h"
# include "MINIRT/world/camera.h"
# include "MINIRT/memory.h"
# include "LIBFT/vector.h"
# include <stdbool.h>
# include <stdint.h>
# include <MLX42/MLX42.h>

# ifndef MRT_AMOUNT_OF_RAYS
#  define MRT_AMOUNT_OF_RAYS 64
# endif

# ifndef MRT_AMOUNT_OF_MATRICES
#  define MRT_AMOUNT_OF_MATRICES 64
# endif

# ifndef MRT_AMOUNT_OF_INTERSECTIONS
#  define MRT_AMOUNT_OF_INTERSECTIONS 64
# endif

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
	bool			render_normal;
};

typedef int	(*t_mrt_renderer)(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

////////////////////////////////////////////
////////////   renderer cache   ////////////
////////////////////////////////////////////

struct s_mrt_renderer_cache
{
	t_ft_vector						intersections;
	struct s_mrt_uniform_allocator	allocators;
};

int							mrt_renderer_cache_init(\
struct s_mrt_renderer_cache *cache, size_t amount_of_objects);

void						mrt_renderer_cache_free(\
struct s_mrt_renderer_cache *cache);

///////////////////////////////////////////
////////////   renderer data   ////////////
///////////////////////////////////////////

struct s_mrt_renderer_data
{
	struct s_mrt_world				*world;
	struct s_mrt_renderer_config	config;
	struct s_mrt_renderer_cache		cache;
};

int							mrt_renderer_data_init(\
struct s_mrt_renderer_data *data, struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

void						mrt_renderer_data_free(\
struct s_mrt_renderer_data *data);

///////////////////////////////////////////////
////////////   renderer pipeline   ////////////
///////////////////////////////////////////////

struct		s_mrt_lighting;

t_mrt_color_unit			mrt_render_lighting(\
struct s_mrt_renderer_data *renderer, struct s_mrt_lighting *lighting_data);

t_mrt_color_unit			mrt_render(struct s_mrt_renderer_data *renderer, \
t_mrt_ray ray, struct s_mrt_intersection intersection);

t_mrt_ray					mrt_render_ray_generate(\
struct s_mrt_camera *camera, uint32_t x, uint32_t y);

t_mrt_color					mrt_render_color_at(\
struct s_mrt_renderer_data *renderer, uint32_t x, uint32_t y);

//////////////////////////////////////////
////////////   ppm renderer   ////////////
//////////////////////////////////////////

struct s_mrt_renderer_ppm
{
	struct s_mrt_renderer_data	renderer_data;
	int							terminal_fd;
	int							file_fd;
};

int							mrt_renderer_ppm_init(\
struct s_mrt_renderer_ppm *ppm, struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

int							mrt_renderer_ppm_end(\
struct s_mrt_renderer_ppm *ppm);

void						mrt_renderer_ppm_free(\
struct s_mrt_renderer_ppm *ppm);

/* ppm renderer function */

int							mrt_renderer_ppm(struct s_mrt_world *world, \
struct s_mrt_renderer_config *config);

////////////////////////////////////////////
////////////   mlx42 renderer   ////////////
////////////////////////////////////////////

/* MLX42 renderer interactive control */

struct s_mrt_mlx42_control
{
	unsigned int	forward : 1;
	unsigned int	backward : 1;
	unsigned int	left : 1;
	unsigned int	right : 1;
	unsigned int	upward : 1;
	unsigned int	downward : 1;
};

bool						mrt_mlx42_control_switch(\
mlx_key_data_t keydata, keys_t key1, keys_t key2);

unsigned int				mrt_mlx42_control_as_int(\
struct s_mrt_mlx42_control control);

/* MLX42 renderer data */

struct s_mrt_renderer_mlx42
{
	struct s_mrt_renderer_data		renderer_data;
	mlx_t							*mlx;
	mlx_image_t						*image;
	struct s_mrt_mlx42_control		control;
};

int							mrt_renderer_mlx42_init(\
struct s_mrt_renderer_mlx42 *renderer, \
struct s_mrt_world *world, struct s_mrt_renderer_config *config);

void						mrt_renderer_mlx42_free(\
struct s_mrt_renderer_mlx42 *renderer);

/* MLX42 renderer functions */

int							mrt_renderer_mlx42(\
struct s_mrt_world *world, struct s_mrt_renderer_config *config);

int							mrt_renderer_mlx42_render(\
struct s_mrt_renderer_mlx42 *renderer);

/* MLX42 renderer hooks */

void						mrt_mlx42_key_hook(\
mlx_key_data_t keydata, struct s_mrt_renderer_mlx42 *renderer);

void						mrt_mlx42_loop_hook(\
struct s_mrt_renderer_mlx42 *renderer);

#endif