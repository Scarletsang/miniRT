/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:10:11 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:15:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "MINIRT/scene.h"
# include "MINIRT/image.h"
# include "MINIRT/renderer.h"

typedef struct s_mrt_scene_entry	t_mrt_world_entry;
typedef t_mrt_scene_entries			t_mrt_world_entries;
typedef struct s_mrt_scene			t_mrt_world_scene;

struct s_mrt_world
{
	t_mrt_renderer					renderer;
	t_mrt_world_scene				scene;
	struct s_mrt_renderer_config	renderer_config;
};

int							mrt_world_init(struct s_mrt_world *world, \
struct s_mrt_scene scene);

void						mrt_world_free(struct s_mrt_world *world);

struct s_mrt_world_entry	*mrt_world_entry_from_scene_entry(\
struct s_mrt_scene_entry *scene_entry);

#endif