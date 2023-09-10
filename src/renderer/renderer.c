/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:09:54 by htsang            #+#    #+#             */
/*   Updated: 2023/09/09 08:42:24 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
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
