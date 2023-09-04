/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:42:22 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 05:37:57 by htsang           ###   ########.fr       */
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

t_mrt_vec3	mrt_lighting_normal_at(struct s_mrt_world_entry object, \
t_mrt_vec3 world_point);

//////////////////////////////////////
////////////   lighting   ////////////
//////////////////////////////////////

/**
 * @brief 
 * @details Data comes from:
 * 1. eye_vector: negate the ray direction
 * 2. hit_position: the point in world space where the ray intersected the object
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
	double						diffuse_effectiveness;
	struct s_mrt_light_point	light_source;
};

void		mrt_lighting_set_position(struct s_mrt_lighting *lighting_data, \
t_mrt_ray *ray, struct s_mrt_intersection intersection);

void		mrt_lighting_set_material(struct s_mrt_lighting *lighting_data, \
struct s_mrt_material *material, struct s_mrt_light_ambient ambient_light);

void		mrt_lighting_set_light_source(struct s_mrt_lighting *lighting_data, \
struct s_mrt_light_point light_source);

t_mrt_color	mrt_lighting_calculate(struct s_mrt_lighting *lighting_data);

void		mrt_lighting_print(struct s_mrt_lighting *lighting_data);

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

void		mrt_lights_calculation_basic(\
struct s_mrt_lights_calculation *result, \
struct s_mrt_lighting *lighting_data);

void		mrt_lights_calculation_reflection(\
struct s_mrt_lights_calculation *result, \
struct s_mrt_lighting *lighting_data);

////////////////////////////////////
////////////   lights   ////////////
////////////////////////////////////

struct s_mrt_lights
{
	t_mrt_vec3	ambient;
	t_mrt_vec3	diffuse;
	t_mrt_vec3	specular;
};

void		mrt_lights_set_ambient(struct s_mrt_lights *lights, \
t_mrt_color effective_color, double ambient_effectiveness);

void		mrt_lights_set_diffuse(struct s_mrt_lights *lights, \
struct s_mrt_lights_calculation *calculation, \
double diffuse_effectiveness);

void		mrt_lights_set_specular(struct s_mrt_lights *lights, \
struct s_mrt_lights_calculation *calculation, \
struct s_mrt_lighting *lighting_data);

t_mrt_vec3	mrt_lights_combine_diffuse_level(struct s_mrt_lights *lights);

t_mrt_vec3	mrt_lights_combine_specular_level(struct s_mrt_lights *lights);

#endif