/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:50:24 by htsang            #+#    #+#             */
/*   Updated: 2023/08/29 21:54:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/memory.h"

inline t_mrt_ray	*mrt_unique_ptr_get_ray(t_mrt_unique_ptr *ptr)
{
	return (ptr->pointer.ray);
}

inline t_mrt_internal_matrix	*mrt_unique_ptr_get_matrix(\
t_mrt_unique_ptr *ptr)
{
	return (ptr->pointer.matrix);
}

t_mrt_unique_ptr	mrt_unique_ptr_empty(void)
{
	return ((t_mrt_unique_ptr){
		.allocator = NULL,
		.pointer = (union u_mrt_unique_data){.address = NULL},
		.borrowed = false
	});
}

bool	mrt_unique_ptr_is_empty(t_mrt_unique_ptr *ptr)
{
	return (ptr->pointer.address == NULL);
}
