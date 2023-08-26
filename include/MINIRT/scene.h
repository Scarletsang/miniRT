/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:59:27 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 04:56:08 by htsang           ###   ########.fr       */
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
	ENTRY_UNKNOWN
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

union u_scene_entry_object			mrt_scene_entry_object_empty(void);

bool								mrt_scene_entry_object_is_empty(\
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
typedef t_ft_vector	t_mrt_scene_unique_identifiers;

///////////////////////////////////
////////////   scene   ////////////
///////////////////////////////////

struct s_mrt_scene
{
	t_mrt_scene_entries				entries;
	t_mrt_scene_unique_identifiers	unique_identifiers;
};

int									mrt_scene_init(struct s_mrt_scene *scene);

void								mrt_scene_free(struct s_mrt_scene *scene);

int									mrt_scene_add_entry(\
struct s_mrt_scene *scene, struct s_mrt_scene_entry entry, bool is_unique);

bool								mrt_scene_has_unique_identifier(\
struct s_mrt_scene *scene, enum e_mrt_scene_entry_identifier identifier);

enum e_mrt_scene_entry_identifier	*mrt_scene_add_unique_identifier(\
struct s_mrt_scene *scene, enum e_mrt_scene_entry_identifier identifier);

#endif