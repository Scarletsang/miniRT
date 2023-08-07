/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:59:27 by htsang            #+#    #+#             */
/*   Updated: 2023/08/07 11:30:07 by htsang           ###   ########.fr       */
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

union scene_entry_object
{
	struct s_mrt_scene_sphere			*sphere;
	struct s_mrt_scene_plane			*plane;
	struct s_mrt_scene_cylinder			*cylinder;
	struct s_mrt_scene_light_ambient	*light_ambient;
	struct s_mrt_scene_light_point		*light_point;
	struct s_mrt_scene_camera			*camera;
};

struct s_mrt_scene_entry
{
	enum s_mrt_scene_entry_identifier	identifier;
	union scene_entry_object			object;
};

bool	mrt_scene_entry_is_empty(struct s_mrt_scene_entry *entry);

typedef	t_ft_vector	t_mrt_scene_entries;

struct s_mrt_scene
{
	t_mrt_scene_entries	entries;
	unsigned int		camera_count;
	unsigned int		light_count;
};

int		mrt_scene_init(struct s_mrt_scene *scene);

void	mrt_scene_free(struct s_mrt_scene *scene);

#endif