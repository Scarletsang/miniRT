/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:01:23 by htsang            #+#    #+#             */
/*   Updated: 2023/06/23 00:02:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_mrt_vec3
{
	float	x;
	float	y;
	float	z;
}				t_mrt_vec3;

/**
 * @brief normal is a vector with length 1
 */
typedef t_mrt_vec3	t_mrt_vec3_unit;

#endif