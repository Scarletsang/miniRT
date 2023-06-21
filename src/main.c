/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:20:29 by htsang            #+#    #+#             */
/*   Updated: 2023/06/21 10:56:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include <MLX42/MLX42.h>

int	main(int argc, const char **argv)
{
	mlx_t					*mlx;
	mlx_image_t 			*image;
	struct s_mrt_settings	settings;

	(void) argc;
	(void) argv;
	settings.width = 800;
	settings.height = 600;
	mlx = mlx_init(settings.width, settings.height, "miniRT", false);
	image = mlx_new_image(mlx, settings.width, settings.height);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
