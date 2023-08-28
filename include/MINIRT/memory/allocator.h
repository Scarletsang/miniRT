/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:23:36 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 21:58:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
# define ALLOCATOR_H

# include <stdlib.h>
# include "LIBFT/vector.h"

///////////////////////////////////////
////////////   allocator   ////////////
///////////////////////////////////////

struct s_mrt_allocator_chunk
{
	struct s_mrt_allocator_chunk	*next;
};

typedef t_ft_vector	t_mrt_allocator_blocks;

struct s_mrt_allocator
{
	t_mrt_allocator_blocks			blocks;
	struct s_mrt_allocator_chunk	*allocation_pointer;
	size_t							size_per_chunk;
	size_t							chunk_per_block;
};

int		mrt_allocator_init(struct s_mrt_allocator *allocator, \
size_t size_per_chunk, size_t chunk_per_block);

void	mrt_allocator_free(struct s_mrt_allocator *allocator);

void	*mrt_allocate(struct s_mrt_allocator *allocator);

void	mrt_free(struct s_mrt_allocator *allocator, void *ptr);

#endif