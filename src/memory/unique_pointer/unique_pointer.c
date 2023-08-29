/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:30:06 by htsang            #+#    #+#             */
/*   Updated: 2023/08/29 21:53:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/memory.h"

t_mrt_unique_ptr	mrt_unique_ray(struct s_mrt_allocator *allocator)
{
	t_mrt_ray	*ray;

	ray = mrt_allocate(allocator);
	if (!ray)
		return (mrt_unique_ptr_empty());
	return ((t_mrt_unique_ptr){
		.allocator = allocator,
		.pointer = (union u_mrt_unique_data){.ray = ray},
		.borrowed = false
	});
}

t_mrt_unique_ptr	mrt_unique_matrix(struct s_mrt_allocator *allocator)
{
	t_mrt_internal_matrix	*matrix;

	matrix = mrt_allocate(allocator);
	if (!matrix)
		return (mrt_unique_ptr_empty());
	return ((t_mrt_unique_ptr){
		.allocator = allocator,
		.pointer = (union u_mrt_unique_data){.matrix = matrix},
		.borrowed = false
	});
}

void	mrt_unique_ptr_free(t_mrt_unique_ptr *unique_ptr)
{
	if (unique_ptr->borrowed)
		return ;
	mrt_free(unique_ptr->allocator, unique_ptr->pointer.address);
	unique_ptr->pointer.address = NULL;
	unique_ptr->borrowed = false;
}

t_mrt_unique_ptr	mrt_borrow(t_mrt_unique_ptr ptr)
{
	ptr.borrowed = true;
	return (ptr);
}

t_mrt_unique_ptr	mrt_use(t_mrt_unique_ptr *ptr)
{
	t_mrt_unique_ptr	unique_ptr;

	unique_ptr = *ptr;
	unique_ptr.borrowed = false;
	*ptr = mrt_unique_ptr_empty();
	return (unique_ptr);
}
