/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:11:50 by htsang            #+#    #+#             */
/*   Updated: 2023/08/26 21:35:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/renderer.h"
#include <MLX42/MLX42.h>

unsigned int	mrt_mlx42_control_as_int(struct s_mrt_mlx42_control control)
{
	return (*(unsigned int *) &control);
}
