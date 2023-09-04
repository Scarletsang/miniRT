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

#endif