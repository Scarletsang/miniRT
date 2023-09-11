/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 02:54:40 by htsang            #+#    #+#             */
/*   Updated: 2023/09/08 03:00:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

enum	e_mrt_program_error_code
{
	MRT_ERROR_FILE_NON_EXISIT,
	MRT_ERROR_FILE_WRONG_EXTENSION,
	MRT_ERROR_WORLD_MISSING_AMBIENT_LIGHT,
	MRT_ERROR_WORLD_MISSING_CAMERA
};

void	mrt_error_printer(enum e_mrt_program_error_code error_code);

#endif