/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:53:53 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 13:36:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/error.h"
#include <stdio.h>

void	mrt_error_printer(enum e_mrt_program_error_code error_code)
{
	if (error_code == MRT_ERROR_FILE_NON_EXISIT)
		printf("Error\nFile does not exist\n");
	else if (error_code == MRT_ERROR_FILE_WRONG_EXTENSION)
		printf("Error\nFile has wrong extension\n");
	else if (error_code == MRT_ERROR_WORLD_MISSING_AMBIENT_LIGHT)
		printf("Error\nWorld is missing ambient light\n");
	else if (error_code == MRT_ERROR_WORLD_MISSING_CAMERA)
		printf("Error\nWorld is missing camera\n");
	else
		printf("Error\nReceived unknown error\n");
}
