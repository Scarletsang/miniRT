/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 03:56:20 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 05:27:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include <math.h>

void	mrt_mlx42_xz_axis_movement(struct s_mrt_scene_camera *scene_camera, \
struct s_mrt_mlx42_control control)
{
	t_mrt_vec3	transform;

	transform = vec3(0, 0, 0);
	if (control.forward)
		transform = vec3_negate(scene_camera->orientation);
	if (control.backward)
		transform = vec3_add(transform, scene_camera->orientation);
	if (control.left)
		transform = vec3_add(transform, vec3(-scene_camera->orientation.x, \
			0, scene_camera->orientation.z));
	if (control.right)
		transform = vec3_add(transform, \
			vec3(scene_camera->orientation.x, 0, -scene_camera->orientation.z));
	transform.y = 0;
	scene_camera->origin = vec3_add(scene_camera->origin, \
		vec3_smultiply(transform, 0.75));
}

t_mrt_vec3	mrt_mlx42_rotate(t_mrt_vec3 v, double xz_theta, double y_theta)
{
	double	cos_theta;
	double	sin_theta;

	cos_theta = cos(xz_theta);
	sin_theta = sin(xz_theta);
	return (vec3(v.x * cos_theta - v.z * sin_theta, \
		v.y * cos(y_theta), \
		v.x * sin_theta + v.z * cos_theta));
}