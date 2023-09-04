/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:09:54 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 12:16:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/renderer/intersection.h"
#include <stdint.h>

int	mrt_renderer_data_init(struct s_mrt_renderer_data *data, \
struct s_mrt_world *world, struct s_mrt_renderer_config *config)
{
	data->world = world;
	data->config = *config;
	if (mrt_renderer_cache_init(&data->cache, world->objects.size))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	mrt_renderer_data_free(struct s_mrt_renderer_data *data)
{
	mrt_renderer_cache_free(&data->cache);
}
