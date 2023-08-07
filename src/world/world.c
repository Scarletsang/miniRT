/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:16:13 by htsang            #+#    #+#             */
/*   Updated: 2023/08/07 11:27:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include <stdlib.h>

int	mrt_world_init(struct s_mrt_world *world)
{
	if (ft_vector_init(&world->lights, \
		sizeof(struct s_mrt_world_entry), 8, mrt_world_entry_free))
		return (EXIT_FAILURE);
	if (ft_vector_init(&world->objects, \
		sizeof(struct s_mrt_world_entry), 8, mrt_world_entry_free))
	{
		ft_vector_free(&world->lights);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	mrt_world_free(struct s_mrt_world *world)
{
	ft_vector_free(&world->lights);
	ft_vector_free(&world->objects);
	mrt_world_entry_free(&world->camera);
}
