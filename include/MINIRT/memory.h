/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:23:36 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 22:38:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "MINIRT/memory/allocator.h"
# include "MINIRT/ray.h"
# include "MINIRT/matrix.h"
# include "MINIRT/intersection.h"

struct s_mrt_uniform_allocator
{
	struct s_mrt_allocator		rays;
	struct s_mrt_allocator		matrices;
	struct s_mrt_allocator		intersections;
};

int							mrt_uniform_allocator_init(\
struct s_mrt_uniform_allocator *allocator, size_t amount_of_rays, \
size_t amount_of_matrices, size_t amount_of_intersections);

void						mrt_uniform_allocator_free(\
struct s_mrt_uniform_allocator *allocator);

t_mrt_ray					*mrt_allocate_ray(\
struct s_mrt_uniform_allocator *allocator);

t_mrt_matrix				*mrt_allocate_matrix(\
struct s_mrt_uniform_allocator *allocator);

struct s_mrt_intersection	*mrt_allocate_intersection(\
struct s_mrt_uniform_allocator *allocator);

#endif