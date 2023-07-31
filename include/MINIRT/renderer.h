/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:00:52 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 16:09:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "MINIRT/unit.h"
# include <stdbool.h>

enum	e_mrt_renderer_type
{
	RENDERER_MLX42,
	RENDERER_PPM
};

struct s_mrt_renderer_config
{
	enum e_mrt_renderer_type	renderer;
	unsigned int				anti_aliasing_sample_count;
	unsigned int				maximum_recursion_depth;
	double						maximum_world_distance;
	unsigned int				thread_count;
};

struct s_mrt_renderer_config	mrt_renderer_config_default(void);

#endif