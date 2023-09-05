/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:10:47 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 12:12:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/memory.h"
#include "MINIRT/memory/allocator.h"
#include "MINIRT/renderer/ray.h"
#include "MINIRT/renderer/intersection.h"
#include "MINIRT/matrix.h"

int	mrt_uniform_allocator_init(struct s_mrt_uniform_allocator *allocator, \
size_t amount_of_rays, size_t amount_of_matrices, \
size_t amount_of_intersections)
{
	allocator->rays.blocks.buffer = NULL;
	allocator->matrices.blocks.buffer = NULL;
	allocator->intersections.blocks.buffer = NULL;
	if (mrt_allocator_init(&allocator->rays, \
		sizeof(t_mrt_ray), amount_of_rays) || \
		mrt_allocator_init(&allocator->matrices, \
		sizeof(t_mrt_internal_matrix), amount_of_matrices) || \
		mrt_allocator_init(&allocator->intersections, \
		sizeof(struct s_mrt_intersection), amount_of_intersections))
	{
		mrt_allocator_free(&allocator->rays);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	mrt_uniform_allocator_free(\
struct s_mrt_uniform_allocator *allocator)
{
	mrt_allocator_free(&allocator->rays);
	mrt_allocator_free(&allocator->matrices);
	mrt_allocator_free(&allocator->intersections);
}

inline t_mrt_ray	*mrt_allocate_ray(struct s_mrt_uniform_allocator *allocator)
{
	return (mrt_allocate(&allocator->rays));
}

inline t_mrt_internal_matrix	*mrt_allocate_matrix(\
struct s_mrt_uniform_allocator *allocator)
{
	return (mrt_allocate(&allocator->matrices));
}

inline struct s_mrt_intersection	*mrt_allocate_intersection(\
struct s_mrt_uniform_allocator *allocator)
{
	return (mrt_allocate(&allocator->intersections));
}
