/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 19:07:04 by htsang            #+#    #+#             */
/*   Updated: 2023/09/11 10:17:50 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/parser/scene_parser.h"
#include "MINIRT/parser/general_parser.h"
#include "MINIRT/error.h"
#include "LIBFT/parser.h"
#include "LIBFT/iostream.h"
#include "LIBFT/string.h"
#include <fcntl.h>
#include <stdlib.h>

static bool	mrt_scene_parser_file_name_is_valid(const char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (false);
	return (ft_strcmp(file_name + len - 3, ".rt") == 0);
}

int	mrt_scene_parser_init(struct s_mrt_scene_parser *parser, \
const char *file_path)
{
	if (!mrt_scene_parser_file_name_is_valid(file_path))
	{
		mrt_error_printer(MRT_ERROR_FILE_WRONG_EXTENSION);
		return (EXIT_FAILURE);
	}
	parser->fd = open(file_path, O_RDONLY, 0644);
	if (parser->fd == -1)
	{
		mrt_error_printer(MRT_ERROR_FILE_NON_EXISIT);
		return (EXIT_FAILURE);
	}
	else if (ft_iostream_init(&parser->iostream))
		return (close(parser->fd), EXIT_FAILURE);
	else if (ft_error_traces_init(&parser->traces, \
		&mrt_syntax_expected_printer, \
		&mrt_syntax_error_printer))
		return (mrt_scene_parser_free(parser), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	mrt_scene_parser_free(struct s_mrt_scene_parser *parser)
{
	if (parser->fd != -1)
		close(parser->fd);
	ft_iostream_free(&parser->iostream);
	ft_error_traces_free(&parser->traces);
}
