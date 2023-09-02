/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:01:23 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 15:02:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_mrt_vec3
{
	double	x;
	double	y;
	double	z;
}				t_mrt_vec3;

// unit vector is a vector with length 1
typedef t_mrt_vec3	t_mrt_vec3_unit;

t_mrt_vec3		vec3(double x, double y, double z);

t_mrt_vec3		vec3_negate(t_mrt_vec3 v);
t_mrt_vec3		vec3_add(t_mrt_vec3 v1, t_mrt_vec3 v2);
t_mrt_vec3		vec3_subtract(t_mrt_vec3 v1, t_mrt_vec3 v2);
t_mrt_vec3		vec3_multiply(t_mrt_vec3 v1, t_mrt_vec3 v2);
t_mrt_vec3		vec3_divide(t_mrt_vec3 v1, t_mrt_vec3 v2);

t_mrt_vec3		vec3_sadd(t_mrt_vec3 v, double t);
t_mrt_vec3		vec3_ssubtract(t_mrt_vec3 v, double t);
t_mrt_vec3		vec3_smultiply(t_mrt_vec3 v, double t);
t_mrt_vec3		vec3_sdivide(t_mrt_vec3 v, double t);

double			vec3_length(const t_mrt_vec3 v);
double			vec3_dot(const t_mrt_vec3 v1, const t_mrt_vec3 v2);
t_mrt_vec3		vec3_cross(const t_mrt_vec3 v1, const t_mrt_vec3 v2);
t_mrt_vec3_unit	vec3_normalize(const t_mrt_vec3 v);

#endif
