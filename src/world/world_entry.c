/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:27:46 by htsang            #+#    #+#             */
/*   Updated: 2023/08/07 22:47:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/world.h"
#include <stdlib.h>

bool	mrt_world_entry_is_empty(struct s_mrt_world_entry *entry)
{
	if (entry->identifier == ENTRY_SPHERE)
		return (entry->object.sphere == NULL);
	else if (entry->identifier == ENTRY_PLANE)
		return (entry->object.plane == NULL);
	else if (entry->identifier == ENTRY_CYLINDER)
		return (entry->object.cylinder == NULL);
	else if (entry->identifier == ENTRY_LIGHT_AMBIENT)
		return (entry->object.light_ambient == NULL);
	else if (entry->identifier == ENTRY_LIGHT_POINT)
		return (entry->object.light_point == NULL);
	else if (entry->identifier == ENTRY_CAMERA)
		return (entry->object.camera == NULL);
	else
		return (true);
}

void	mrt_world_entry_free(struct s_mrt_world_entry *entry)
{
	if (mrt_world_entry_is_empty(entry))
		return ;
	else if (entry->identifier == ENTRY_SPHERE)
		free(entry->object.sphere);
	else if (entry->identifier == ENTRY_PLANE)
		free(entry->object.plane);
	else if (entry->identifier == ENTRY_CYLINDER)
		free(entry->object.cylinder);
	else if (entry->identifier == ENTRY_LIGHT_AMBIENT)
		free(entry->object.light_ambient);
	else if (entry->identifier == ENTRY_LIGHT_POINT)
		free(entry->object.light_point);
	else if (entry->identifier == ENTRY_CAMERA)
		free(entry->object.camera);
}
