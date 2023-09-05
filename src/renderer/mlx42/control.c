/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:11:50 by htsang            #+#    #+#             */
/*   Updated: 2023/09/02 15:51:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/miniRT.h"
#include "MINIRT/renderer.h"
#include <MLX42/MLX42.h>

bool	mrt_mlx42_control_switch(mlx_key_data_t keydata, keys_t key1, \
keys_t key2)
{
	return (((keydata.key == key1) || (keydata.key == key2)) \
		&& keydata.action != MLX_REPEAT);
}

unsigned int	mrt_mlx42_control_as_int(struct s_mrt_mlx42_control control)
{
	return (*(unsigned int *) &control);
}
