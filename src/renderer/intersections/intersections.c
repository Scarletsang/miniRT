/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:18:17 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 15:53:38 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/memory.h"
#include "MINIRT/renderer/intersection.h"
#include "LIBFT/vector.h"

int	mrt_intersections_init(t_mrt_intersections *intersections, \
size_t amount_of_objects)
{
	return (ft_vector_init(intersections, \
		sizeof(struct s_mrt_intersection *), amount_of_objects * 2, \
		ft_vector_copy_ptr));
}

void	mrt_intersections_reset(t_mrt_intersections *intersections, \
struct s_mrt_uniform_allocator *uniform_allocator)
{
	t_ft_vector_iterator	iterator;

	ft_vector_iterator_begin(&iterator, intersections);
	while (!iterator.is_end)
	{
		mrt_free(&uniform_allocator->intersections, \
			*(struct s_mrt_intersection **) \
				ft_vector_iterator_current(&iterator));
		ft_vector_iterator_next(&iterator);
	}
	intersections->size = 0;
}

int	mrt_intersections_add(t_mrt_intersections *intersections, \
struct s_mrt_intersection *intersection)
{
	return (!ft_vector_append(intersections, &intersection));
}

struct s_mrt_intersection	mrt_intersections_nearest(\
t_mrt_intersections *intersections)
{
	t_ft_vector_iterator		iterator;

	ft_vector_iterator_begin(&iterator, intersections);
	while (!iterator.is_end)
	{
		if ((*(struct s_mrt_intersection **) \
			ft_vector_iterator_current(&iterator))->time >= 0)
			return (**(struct s_mrt_intersection **) \
				ft_vector_iterator_current(&iterator));
		ft_vector_iterator_next(&iterator);
	}
	return (mrt_intersection_empty());
}
