/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:59:27 by htsang            #+#    #+#             */
/*   Updated: 2023/08/15 14:19:14 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "LIBFT/vector.h"

/////////////////////////////////////////
////////////   scene entry   ////////////
/////////////////////////////////////////

enum	e_mrt_scene_entry_identifier
{
	ENTRY_SPHERE,
	ENTRY_PLANE,
	ENTRY_CYLINDER,
	ENTRY_LIGHT_AMBIENT,
	ENTRY_LIGHT_POINT,
	ENTRY_CAMERA,
	ENTRY_UNKNOWN,
	ENTRY_ZERO
};

union u_scene_entry_object
{
	struct s_mrt_scene_sphere			*sphere;
	struct s_mrt_scene_plane			*plane;
	struct s_mrt_scene_cylinder			*cylinder;
	struct s_mrt_scene_light_ambient	*light_ambient;
	struct s_mrt_scene_light_point		*light_point;
	struct s_mrt_scene_camera			*camera;
};

union u_scene_entry_object	mrt_scene_entry_object_empty(void);

bool						mrt_scene_entry_object_is_empty(\
union u_scene_entry_object entry);

struct s_mrt_scene_entry
{
	enum e_mrt_scene_entry_identifier	identifier;
	union u_scene_entry_object			object;
};

///////////////////////////////////////////
////////////   scene entries   ////////////
///////////////////////////////////////////

typedef t_ft_vector	t_mrt_scene_entries;

///////////////////////////////////
////////////   scene   ////////////
///////////////////////////////////

struct s_mrt_scene
{
	t_mrt_scene_entries	entries;
	unsigned int		camera_count;
	unsigned int		light_count;
};

int							mrt_scene_init(struct s_mrt_scene *scene);

void						mrt_scene_free(struct s_mrt_scene *scene);

int							mrt_scene_add_entry(struct s_mrt_scene *scene, \
	struct s_mrt_scene_entry entry);

#endif