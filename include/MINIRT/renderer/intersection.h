/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:33:03 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 12:17:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "MINIRT/world.h"
# include "MINIRT/memory.h"
# include <stdbool.h>

//////////////////////////////////////////
////////////   intersection   ////////////
//////////////////////////////////////////

struct s_mrt_intersection
{
	double						time;
	struct s_mrt_world_entry	object;
};

struct s_mrt_intersection	mrt_intersection(double time, \
struct s_mrt_world_entry object);

bool						mrt_intersection_is_empty(\
struct s_mrt_intersection *intersection);

struct s_mrt_intersection	mrt_intersection_empty(void);

/////////////////////////////////////////////////////
////////////   intersect ray on object   ////////////
/////////////////////////////////////////////////////

struct s_mrt_intersection	mrt_intersect_object(\
struct s_mrt_world_entry object, struct s_mrt_ray *ray);

double						mrt_intersect_sphere(struct s_mrt_sphere *sphere, \
struct s_mrt_ray *ray);

double						mrt_intersect_plane(struct s_mrt_plane *plane, \
struct s_mrt_ray *ray);

bool						mrt_intersect_cylinder(\
struct s_mrt_cylinder *cylinder, struct s_mrt_ray *ray);

////////////////////////////////////////////////////
////////////   intersect ray on world   ////////////
////////////////////////////////////////////////////

struct				s_mrt_renderer_data;

struct s_mrt_intersection	mrt_intersect_world(\
struct s_mrt_renderer_data *renderer, t_mrt_ray ray);

///////////////////////////////////////////
////////////   intersections   ////////////
///////////////////////////////////////////

typedef t_ft_vector	t_mrt_intersections;

int							mrt_intersections_init(\
t_mrt_intersections *intersections, size_t amount_of_objects);

void						mrt_intersections_reset(\
t_mrt_intersections *intersections, \
struct s_mrt_uniform_allocator *uniform_allocator);

int							mrt_intersections_add(\
t_mrt_intersections *intersections, struct s_mrt_intersection *intersection);

void						mrt_intersections_sort(\
t_mrt_intersections *intersections);

struct s_mrt_intersection	mrt_intersections_nearest(\
t_mrt_intersections *intersections);

#endif