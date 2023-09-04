/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cache.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:59:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/03 19:24:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/memory.h"
#include "LIBFT/vector.h"
#include <stdint.h>

int	mrt_renderer_cache_init(struct s_mrt_renderer_cache *cache, \
size_t amount_of_objects)
{
	if (mrt_uniform_allocator_init(&cache->allocators, MRT_AMOUNT_OF_RAYS, \
		MRT_AMOUNT_OF_MATRICES, MRT_AMOUNT_OF_INTERSECTIONS))
		return (EXIT_FAILURE);
	if (mrt_intersections_init(&cache->intersections, amount_of_objects))
	{
		mrt_uniform_allocator_free(&cache->allocators);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	mrt_renderer_cache_free(struct s_mrt_renderer_cache *cache)
{
	mrt_uniform_allocator_free(&cache->allocators);
	ft_vector_free(&cache->intersections);
}
