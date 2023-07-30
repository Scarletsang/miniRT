/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:08:43 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 11:08:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_mrt_image
{
	double	aspect_ratio;
	int		image_width;
	int		image_height;
}				t_mrt_image;

const t_mrt_image	*new_image(void);

#endif