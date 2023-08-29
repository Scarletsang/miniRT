/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:23:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/29 21:56:23 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/memory/allocator.h"
#include "LIBFT/vector.h"
#include <stdlib.h>
#include <assert.h>

int	mrt_allocator_init(struct s_mrt_allocator *allocator, \
size_t size_per_chunk, size_t chunk_per_block)
{
	assert(size_per_chunk <= SIZE_MAX - chunk_per_block);
	assert(chunk_per_block > 0);
	assert(size_per_chunk > 0);
	if (ft_vector_init(&allocator->blocks, sizeof(void *), 8, \
		&ft_vector_copy_ptr))
		return (EXIT_FAILURE);
	allocator->avaliable = NULL;
	allocator->size_per_chunk = size_per_chunk;
	allocator->chunk_per_block = chunk_per_block;
	return (EXIT_SUCCESS);
}

void	mrt_allocator_free(struct s_mrt_allocator *allocator)
{
	void	**block;
	size_t	i;

	i = 0;
	while (i < allocator->blocks.size)
	{
		block = ft_vector_get(&allocator->blocks, i);
		free(*block);
		i++;
	}
	ft_vector_free(&allocator->blocks);
}

static void	*mrt_pool_allocator_allocate_block(\
struct s_mrt_allocator *allocator)
{
	unsigned char					*block;
	struct s_mrt_allocator_chunk	*chunk;
	struct s_mrt_allocator_chunk	*next_chunk;
	size_t							i;

	block = malloc(allocator->size_per_chunk * allocator->chunk_per_block);
	if (!block)
		return (NULL);
	else if (!ft_vector_append(&allocator->blocks, &block))
		return (free(block), NULL);
	i = 0;
	chunk = (struct s_mrt_allocator_chunk *)block;
	while (i++ < (allocator->chunk_per_block - 1))
	{
		next_chunk = (struct s_mrt_allocator_chunk *)(\
			(unsigned char *) chunk + allocator->size_per_chunk);
		chunk->next = next_chunk;
		chunk = next_chunk;
	}
	chunk->next = NULL;
	if (!allocator->avaliable)
		allocator->avaliable = (struct s_mrt_allocator_chunk *)block;
	else
		allocator->avaliable->next = (struct s_mrt_allocator_chunk *)block;
	return (block);
}

void	*mrt_allocate(struct s_mrt_allocator *allocator)
{
	void	*ptr;

	if (!allocator->avaliable)
	{
		allocator->avaliable = \
			mrt_pool_allocator_allocate_block(allocator);
		if (!allocator->avaliable)
			return (NULL);
	}
	ptr = allocator->avaliable;
	allocator->avaliable = allocator->avaliable->next;
	return (ptr);
}

void	mrt_free(struct s_mrt_allocator *allocator, void *ptr)
{
	struct s_mrt_allocator_chunk	*chunk;

	chunk = (struct s_mrt_allocator_chunk *)ptr;
	chunk->next = allocator->avaliable;
	allocator->avaliable = chunk;
}
