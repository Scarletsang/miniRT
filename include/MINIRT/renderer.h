/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:00:52 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 20:35:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "MINIRT/unit.h"
# include "MINIRT/world.h"
# include <stdbool.h>

struct s_mrt_renderer_config
{
	unsigned int	anti_aliasing_sample_count;
	unsigned int	maximum_recursion_depth;
	double			maximum_world_distance;
	unsigned int	thread_count;
	const char		*ppm_output_file_name;
};

struct s_mrt_renderer_config	mrt_renderer_config_default(void);

typedef	int	(*t_mrt_renderer)(t_mrt_world_scene	*scene, \
struct s_mrt_image *viewport, struct s_mrt_renderer_config *config);

int								mrt_renderer_ppm(t_mrt_world_scene	*scene, \
struct s_mrt_image *viewport, struct s_mrt_renderer_config *config);

#endif