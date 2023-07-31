/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:59:27 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 16:24:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "LIBFT/vector.h"

enum	s_mrt_scene_entry_identifier
{
	ENTRY_SPHERE,
	ENTRY_PLANE,
	ENTRY_CYLINDER,
	ENTRY_LIGHT_AMBIENT,
	ENTRY_LIGHT_POINT,
	ENTRY_CAMERA,
	ENTRY_UNKNOWN
};

struct s_mrt_scene_entry
{
	enum s_mrt_scene_entry_identifier	identifier;
	void								*object;
};

typedef	t_ft_vector	t_mrt_scene_entries;

struct s_mrt_scene
{
	t_mrt_scene_entries			lights;
	t_mrt_scene_entries			objects;
	struct s_mrt_scene_entry	camera;
};

#endif