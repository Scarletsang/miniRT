/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:47:09 by kisikogl          #+#    #+#             */
/*   Updated: 2023/07/27 11:20:36 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/unit.h"
#include <stdio.h>

t_mrt_vec3 vec3(double x, double y, double z)
{
	t_mrt_vec3 v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	vec3_color_write(t_mrt_color pixel_color)
{
	printf("%d %d %d\n"
		, (int) (255.999 * pixel_color.x)
		, (int) (255.999 * pixel_color.y)
		, (int) (255.999 * pixel_color.z));
}