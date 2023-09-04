/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:01:01 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 09:44:51 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2_H
# define VEC2_H

typedef struct s_mrt_vec2
{
	double	x;
	double	y;
}				t_mrt_vec2;

t_mrt_vec2		vec2(double x, double y);

typedef t_mrt_vec2	t_mrt_t1t2;

#endif