/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:09:54 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 20:11:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"

struct s_mrt_renderer_config	mrt_renderer_config_default(void)
{
	return ((struct s_mrt_renderer_config) {
		.anti_aliasing_sample_count = 1,
		.maximum_recursion_depth = 5,
		.maximum_world_distance = 1000000.0,
		.thread_count = 1
	});
}
