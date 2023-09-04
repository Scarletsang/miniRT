/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 04:20:51 by htsang            #+#    #+#             */
/*   Updated: 2023/09/04 12:15:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"
#include "MINIRT/world.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int	mrt_renderer_ppm_init(struct s_mrt_renderer_ppm *ppm, \
struct s_mrt_world *world, struct s_mrt_renderer_config *config)
{
	*ppm = (struct s_mrt_renderer_ppm){
		.renderer_data = (struct s_mrt_renderer_data){0},
		.file_fd = open(config->ppm_output_file_name, \
		O_CREAT | O_WRONLY | O_TRUNC, 0644),
		.terminal_fd = dup(STDOUT_FILENO)
	};
	if (ppm->file_fd < 0 || ppm->terminal_fd < 0 || \
		mrt_renderer_data_init(&ppm->renderer_data, world, config))
		return (mrt_renderer_ppm_free(ppm), EXIT_FAILURE);
	if (dup2(ppm->file_fd, STDOUT_FILENO) < 0)
		return (mrt_renderer_ppm_free(ppm), EXIT_FAILURE);
	if (close(ppm->file_fd) < 0)
		return (mrt_renderer_ppm_free(ppm), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	mrt_renderer_ppm_end(struct s_mrt_renderer_ppm *ppm)
{
	mrt_renderer_data_free(&ppm->renderer_data);
	if (dup2(ppm->terminal_fd, STDOUT_FILENO) < 0)
	{
		close(ppm->terminal_fd);
		return (EXIT_FAILURE);
	}
	else if (close(ppm->terminal_fd) < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	mrt_renderer_ppm_free(struct s_mrt_renderer_ppm *ppm)
{
	mrt_renderer_data_free(&ppm->renderer_data);
	if (ppm->file_fd >= 0)
		close(ppm->file_fd);
	if (ppm->terminal_fd >= 0)
		close(ppm->terminal_fd);
}
