/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 22:59:34 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 13:30:34 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "MINIRT/unit.h"

double	mrt_lerp(t_mrt_range range, float percentage)
{
	return (mrt_range_size(range) * percentage + mrt_range_minimum(range));
}

double	mrt_inverse_lerp(t_mrt_range range, float value)
{
	return ((value - mrt_range_minimum(range)) / mrt_range_size(range));
}

double	mrt_remap(t_mrt_range input_range, t_mrt_range output_range, \
	float value)
{
	float	percentage;

	percentage = mrt_inverse_lerp(input_range, value);
	return (mrt_lerp(output_range, percentage));
}

int	test_remap(int argc, const char **argv)
{
	t_mrt_range	input_range;
	t_mrt_range	normalized_range;
	double		step;
	double		value;

	if (argc < 3)
		return (EXIT_FAILURE);
	input_range = mrt_range(atof(argv[1]), atof(argv[2]));
	normalized_range = mrt_range(0, 1);
	value = mrt_range_minimum(input_range);
	step = mrt_range_size(input_range) / 11;
	while (value <= mrt_range_maximum(input_range))
	{
		printf("value: %f, remap: %f\n", value, \
			mrt_remap(input_range, normalized_range, value));
		value += step;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, const char **argv)
{
	return (test_remap(argc, argv));
}
