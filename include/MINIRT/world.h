/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:10:11 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 01:48:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "MINIRT/scene.h"
# include "MINIRT/image.h"
# include "MINIRT/renderer.h"
# include "MINIRT/world/camera.h"
# include "MINIRT/world/light.h"
# include "MINIRT/world/game_object.h"

/////////////////////////////////////////
////////////   world entry   ////////////
/////////////////////////////////////////

union u_world_entry_object
{
	struct s_mrt_sphere			*sphere;
	struct s_mrt_plane			*plane;
	struct s_mrt_cylinder		*cylinder;
	struct s_mrt_light_ambient	*light_ambient;
	struct s_mrt_light_point	*light_point;
	struct s_mrt_camera			*camera;
	void						*address;
};

struct s_mrt_world_entry
{
	enum e_mrt_scene_entry_identifier	identifier;
	union u_world_entry_object			object;
};

bool						mrt_world_entry_is_empty(\
struct s_mrt_world_entry *entry);

void						mrt_world_entry_free(\
struct s_mrt_world_entry *entry);

///////////////////////////////////////////
////////////   world entries   ////////////
///////////////////////////////////////////

typedef t_ft_vector	t_mrt_world_entries;

void						mrt_world_entries_free(t_mrt_world_entries *entry);

///////////////////////////////////
////////////   world   ////////////
///////////////////////////////////

struct s_mrt_world
{
	t_mrt_world_entries			objects;
	t_mrt_world_entries			point_lights;
	struct s_mrt_world_entry	ambient_light;
	struct s_mrt_world_entry	camera;
};

struct s_mrt_camera			*mrt_world_get_camera(struct s_mrt_world *world);

t_mrt_vec3					mrt_world_normal_at(\
struct s_mrt_world_entry object, t_mrt_vec3 world_point);

///////////////////////////////////////////
////////////   world options   ////////////
///////////////////////////////////////////

struct s_mrt_world_options
{
	struct s_mrt_image	camera_image;
	double				camera_focal_length;
};

int							mrt_world_init(struct s_mrt_world *world);

void						mrt_world_free(struct s_mrt_world *world);

int							mrt_world_from_scene(struct s_mrt_scene *scene, \
struct s_mrt_world *world, struct s_mrt_world_options options);

#endif