/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:33:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 23:50:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/intersection.h"
#include "MINIRT/unit.h"
#include <math.h>

/**
 * @details
 * (-a - b) / 2c = -a/2c - b/2c
 * (-a + b) / 2c = -a/2c + b/2c
 * So if i precalculated b/2c, i can just add or subtract it from -a/2c
 * to get the roots.
*/
static double	mrt_quadratic_cloest_root_internal(\
t_mrt_vec3	quadratic, double discriminant)
{
	t_mrt_vec2	roots;

	roots = mrt_quadratic_roots(quadratic, discriminant);
	if (roots.x < 0 && roots.y < 0)
		return (-1);
	else if (roots.x < 0 && roots.y > 0)
		return (roots.y);
	else if (roots.x > 0 && roots.y < 0)
		return (roots.x);
	else if (roots.x > roots.y)
		return (roots.y);
	else
		return (roots.x);
}

t_mrt_vec2	mrt_quadratic_roots(t_mrt_vec3 quadratic, double discriminant)
{
	double	discriminant_divides_2a;
	double	minus_b_divides_2a;
	double	t1;
	double	t2;

	discriminant = mrt_quadratic_discriminant(quadratic);
	if (discriminant < 0)
		return (vec2(-1, -1));
	discriminant_divides_2a = sqrt(discriminant) / (2 * quadratic.x);
	minus_b_divides_2a = -quadratic.y / (2 * quadratic.x);
	t1 = discriminant_divides_2a - minus_b_divides_2a;
	t2 = discriminant_divides_2a + minus_b_divides_2a;
	return (vec2(t1, t2));
}

inline double	mrt_quadratic_discriminant(t_mrt_vec3 quadratic)
{
	return (quadratic.y * quadratic.y - 4 * quadratic.x * quadratic.z);
}

double	mrt_quadratic_closest_root(t_mrt_vec3 quadratic)
{
	double	discriminant;

	discriminant = mrt_quadratic_discriminant(quadratic);
	if (discriminant < 0)
		return (-1);
	return (mrt_quadratic_cloest_root_internal(quadratic, discriminant));
}
