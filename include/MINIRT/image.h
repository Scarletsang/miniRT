/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 18:15:28 by htsang            #+#    #+#             */
/*   Updated: 2023/08/06 19:09:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

struct s_mrt_image
{
	double	aspect_ratio;
	int		width;
	int		height;
};

struct s_mrt_image	mrt_image_fixed_width(double aspect_ratio, int width);

struct s_mrt_image	mrt_image_fixed_height(double aspect_ratio, int height);

struct s_mrt_image	mrt_image_fixed_dimension(int width, int height);

struct s_mrt_image	mrt_image_default(void);

#endif