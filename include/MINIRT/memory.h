/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:23:36 by htsang            #+#    #+#             */
/*   Updated: 2023/08/30 17:56:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "MINIRT/memory/allocator.h"
# include <stddef.h>

typedef struct s_mrt_internal_matrix	t_mrt_internal_matrix;
typedef struct s_mrt_ray				t_mrt_ray;

struct s_mrt_uniform_allocator
{
	struct s_mrt_allocator		rays;
	struct s_mrt_allocator		matrices;
};

int							mrt_uniform_allocator_init(\
struct s_mrt_uniform_allocator *allocator, size_t amount_of_rays, \
size_t amount_of_matrices);

void						mrt_uniform_allocator_free(\
struct s_mrt_uniform_allocator *allocator);

t_mrt_ray					*mrt_allocate_ray(\
struct s_mrt_uniform_allocator *allocator);

t_mrt_internal_matrix		*mrt_allocate_matrix(\
struct s_mrt_uniform_allocator *allocator);

////////////////////////////////////////////
////////////   unique pointer   ////////////
////////////////////////////////////////////

union	u_mrt_unique_data
{
	t_mrt_ray				*ray;
	t_mrt_internal_matrix	*matrix;
	void					*address;
};

typedef struct s_mrt_unique_ptr
{
	struct s_mrt_allocator	*allocator;
	union u_mrt_unique_data	pointer;
	bool					borrowed;
}				t_mrt_unique_ptr;

t_mrt_unique_ptr			mrt_unique_ray(\
struct s_mrt_allocator *allocator);

t_mrt_unique_ptr			mrt_unique_matrix(\
struct s_mrt_allocator *allocator);

void						mrt_unique_ptr_free(t_mrt_unique_ptr *ptr);

t_mrt_unique_ptr			mrt_unique_ptr_borrow(t_mrt_unique_ptr ptr);

t_mrt_unique_ptr			mrt_unique_ptr_use(t_mrt_unique_ptr *ptr);

t_mrt_unique_ptr			mrt_unique_ptr_empty(void);

bool						mrt_unique_ptr_is_empty(t_mrt_unique_ptr *ptr);

t_mrt_ray					*mrt_unique_ptr_get_ray(t_mrt_unique_ptr *ptr);

t_mrt_internal_matrix		*mrt_unique_ptr_get_matrix(t_mrt_unique_ptr *ptr);

typedef t_mrt_unique_ptr				t_mrt_unique_ray;

#endif