/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:53:44 by htsang            #+#    #+#             */
/*   Updated: 2023/08/08 10:52:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/scene.h"

union u_scene_entry_object	mrt_scene_entry_object_empty(void)
{
	return ((union u_scene_entry_object){.camera = NULL});
}

bool	mrt_scene_entry_object_is_empty(union u_scene_entry_object entry_object)
{
	return (entry_object.camera == NULL);
}
