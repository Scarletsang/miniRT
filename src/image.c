/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:01:14 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:09:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/image.h"

struct s_mrt_image	mrt_image_fixed_width(double aspect_ratio, int width)
{
	return ((struct s_mrt_image){
		.aspect_ratio = aspect_ratio,
		.width = width,
		.height = width / aspect_ratio});
}

struct s_mrt_image	mrt_image_fixed_height(double aspect_ratio, int height)
{
	return ((struct s_mrt_image){
		.aspect_ratio = aspect_ratio,
		.width = height * aspect_ratio,
		.height = height});
}

struct s_mrt_image	mrt_image_fixed_dimension(int width, int height)
{
	return ((struct s_mrt_image){
		.aspect_ratio = (double) width / (double) height,
		.width = width,
		.height = height});
}

struct s_mrt_image	mrt_image_default(void)
{
	return (mrt_image_fixed_width(16.0 / 9.0, 400));
}
