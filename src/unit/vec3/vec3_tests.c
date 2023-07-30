/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:12:20 by kisikogl          #+#    #+#             */
/*   Updated: 2023/07/27 11:23:09 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"

// VECTOR FUNCTIONS TEST:

/*
#include <stdio.h>

void print_vector(const char* label, const t_mrt_vec3* v) {
    printf("%s: %.2f, %.2f, %.2f\n", label, v->x, v->y, v->z);
}

int main() {
    // Create some test vectors
    t_mrt_vec3 v1 = vec3(1.0, 2.0, 3.0);
    t_mrt_vec3 v2 = vec3(4.0, 5.0, 6.0);
    double scalar = 2.0;

    // Perform vector operations
    t_mrt_vec3 negated = vec3_negate(&v1);
    t_mrt_vec3 added = vec3_add(&v1, &v2);
    t_mrt_vec3 multiplied = vec3_multiply(&v1, scalar);
    t_mrt_vec3 divided = vec3_divide(&v2, scalar);
    double length = vec3_length(&v1);
    double dot_product = vec3_dot(&v1, &v2);
    t_mrt_vec3 cross_product = vec3_cross(&v1, &v2);
    t_mrt_vec3 unit_vector = vec3_normalize(&v1);

    // Print the results
    print_vector("Original Vector 1", &v1);
    print_vector("Original Vector 2", &v2);
    print_vector("Negated Vector", &negated);
    print_vector("Added Vectors", &added);
    print_vector("Multiplied Vector", &multiplied);
    print_vector("Divided Vector", &divided);
    printf("Length of Vector 1: %.2f\n", length);
    printf("Dot Product of Vectors: %.2f\n", dot_product);
    print_vector("Cross Product of Vectors", &cross_product);
    print_vector("Unit Vector", &unit_vector);

    return 0;
}
*/

// PPM IMAGE TEST:
/*
#include <stdio.h>

int	main(void)
{
	const int	img_width = 256;
	const int	img_height = 256;

	printf("P3\n%d %d\n255\n", img_width, img_height);

	for (int y = img_height - 1; y >= 0; y--)
	{
		fprintf(stderr, "\rScanlines remaining: %d", y);
		fflush(stderr);
		for (int x = 0; x < img_width; x++)
		{
			vec3_color_write(vec3((double)x / (img_width - 1), (double)y / (img_height - 1), 0.25));
		}
	}
	fprintf(stderr, "\nDone.\n");
	return (0);
}
*/