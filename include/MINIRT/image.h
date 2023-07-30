/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:08:43 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 12:06:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

struct s_mrt_image
{
	double	aspect_ratio;
	int		image_width;
	int		image_height;
};

const struct s_mrt_image	*new_image(void);

#endif