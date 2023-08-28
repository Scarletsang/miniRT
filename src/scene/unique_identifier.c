/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unique_identifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:46:27 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 01:34:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"

bool	mrt_scene_has_unique_identifier(struct s_mrt_scene *scene, \
enum e_mrt_scene_entry_identifier identifier)
{
	t_ft_vector_iterator	iterator;

	ft_vector_iterator_begin(&iterator, &scene->unique_identifiers);
	while (!iterator.is_end)
	{
		if (*(enum e_mrt_scene_entry_identifier *) \
			ft_vector_iterator_current(&iterator) == identifier)
			return (true);
		ft_vector_iterator_next(&iterator);
	}
	return (false);
}

enum e_mrt_scene_entry_identifier	*mrt_scene_add_unique_identifier(\
struct s_mrt_scene *scene, enum e_mrt_scene_entry_identifier identifier)
{
	return (ft_vector_append(&scene->unique_identifiers, &identifier));
}
