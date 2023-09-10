/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:42:22 by htsang            #+#    #+#             */
/*   Updated: 2023/09/10 12:55:16 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "MINIRT/unit.h"
# include "MINIRT/scene/s_objects.h"
# include "MINIRT/world/game_object.h"
# include "MINIRT/world.h"
# include "MINIRT/renderer/intersection.h"
# include "MINIRT/renderer/ray.h"

////////////////////////////////////////////////////////////////////
////////////   finding normal of a point on an object   ////////////
////////////////////////////////////////////////////////////////////

t_mrt_vec3			mrt_lighting_normal_at_cylinder(\
struct s_mrt_cylinder *cylinder, t_mrt_vec3 world_point);

t_mrt_vec3			mrt_lighting_normal_at_sphere(\
struct s_mrt_sphere *sphere, t_mrt_vec3 world_point);

t_mrt_vec3			mrt_lighting_normal_at_plane(struct s_mrt_plane *plane, \
t_mrt_vec3 world_point);

//////////////////////////////////////
////////////   lighting   ////////////
//////////////////////////////////////

/**
 * @brief
 * @details Data comes from:
 * 1. eye_vector: negate the ray direction
 * 2. hit_position: the point in world space where the ray intersected the objct
 * 3. normal: the normal vector of the surface at the point of intersection
 * 4. material: the material of the object at the point of intersection
 * 5. light: the light source
 * 6. light_position: the position of the light source
*/
struct s_mrt_lighting
{
	t_mrt_vec3					eye_vector;
	t_mrt_vec3					hit_position;
	t_mrt_vec3					normal;
	struct s_mrt_material		material;
	double						ambient_effectiveness;
	struct s_mrt_light_point	light_source;
};

void				mrt_lighting_prepare(struct s_mrt_lighting *lighting_data, \
t_mrt_ray *ray, struct s_mrt_intersection intersection, \
struct s_mrt_light_ambient *ambient_light);

void				mrt_lighting_set_light_source(\
struct s_mrt_lighting *lighting_data, struct s_mrt_light_point light_source);

struct				s_mrt_renderer_config;

t_mrt_percentage	mrt_lighting_calculate(\
struct s_mrt_lighting *lighting_data, struct s_mrt_renderer_data *renderer);

void				mrt_lighting_print(struct s_mrt_lighting *lighting_data);

///////////////////////////////////////////////////////////////
////////////   internal calculation for lighting   ////////////
///////////////////////////////////////////////////////////////

struct s_mrt_lights_calculation
{
	t_mrt_vec3	lightv;
	double		light_normal_angle;
	t_mrt_color	effective_color;
	t_mrt_vec3	reflectv;
	double		reflect_eye_angle;
};

void				mrt_lights_calculation_basic(\
struct s_mrt_lights_calculation *result, \
struct s_mrt_lighting *lighting_data);

void				mrt_lights_calculation_reflection(\
struct s_mrt_lights_calculation *result, \
struct s_mrt_lighting *lighting_data);

////////////////////////////////////
////////////   lights   ////////////
////////////////////////////////////

void				mrt_lights_add_ambient(t_mrt_percentage *lights, \
t_mrt_color material_color, double ambient_effectiveness);

void				mrt_lights_add_diffuse(t_mrt_percentage *lights, \
struct s_mrt_lights_calculation *calculation, \
double diffuse_effectiveness);

void				mrt_lights_add_specular(t_mrt_percentage *lights, \
struct s_mrt_lights_calculation *calculation, \
struct s_mrt_lighting *lighting_data);

/////////////////////////////////////
////////////   shading   ////////////
/////////////////////////////////////

bool	mrt_is_shadow(struct s_mrt_lighting *lighting_data, \
	struct s_mrt_renderer_data *renderer, t_mrt_vec3 lightv);

#endif