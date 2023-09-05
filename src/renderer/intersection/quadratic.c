/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 23:33:32 by htsang            #+#    #+#             */
/*   Updated: 2023/09/05 13:52:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer/intersection.h"
#include "MINIRT/unit.h"
#include <math.h>

double	mrt_quadratic_smallest_root(t_mrt_vec2 roots)
{
	if (roots.x < 0 && roots.y < 0)
		return (-1);
	else if (roots.x < 0 && roots.y >= 0)
		return (roots.y);
	else if (roots.x >= 0 && roots.y < 0)
		return (roots.x);
	else if (roots.x > roots.y)
		return (roots.y);
	else
		return (roots.x);
}

/**
 * @details
 * (-b - sqrtd) / 2a = -b/2a - sqrtd/2a
 * (-b + sqrtd) / 2a = -b/2a + sqrtd/2a
 * So if i precalculated b/2c, i can just add or subtract it from -a/2c
 * to get the roots.
*/
t_mrt_vec2	mrt_quadratic_roots(t_mrt_vec3 quadratic, double discriminant)
{
	double	sqrt_discriminant;
	double	two_a;
	double	t1;
	double	t2;

	discriminant = mrt_quadratic_discriminant(quadratic);
	if (discriminant < 0)
		return (vec2(-1, -1));
	sqrt_discriminant = sqrt(discriminant);
	two_a = 2 * quadratic.x;
	t1 = (-quadratic.y - sqrt_discriminant) / two_a;
	t2 = (-quadratic.y + sqrt_discriminant) / two_a;
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
	return (mrt_quadratic_smallest_root(\
		mrt_quadratic_roots(quadratic, discriminant)));
}
