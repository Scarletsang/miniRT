/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:07:59 by htsang            #+#    #+#             */
/*   Updated: 2023/07/27 13:24:22 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "unit.h"
# include "image.h"

typedef struct s_mrt_camera
{
	double			viewport_height;
	double			viewport_width;
	double			focal_length;
	t_mrt_vec3		origin;
	t_mrt_vec3		horizontal;
	t_mrt_vec3		vertical;
	t_mrt_vec3		lower_left_corner;
}				t_mrt_camera;

t_mrt_camera	*new_camera(const t_mrt_image *img);

#endif