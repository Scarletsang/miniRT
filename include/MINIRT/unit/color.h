/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:02:14 by htsang            #+#    #+#             */
/*   Updated: 2023/07/30 13:08:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "MINIRT/unit/vec3.h"

typedef t_mrt_vec3	t_mrt_color;

void	vec3_color_write(t_mrt_color pixel_color);

#endif