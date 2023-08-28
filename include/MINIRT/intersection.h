/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:33:03 by htsang            #+#    #+#             */
/*   Updated: 2023/08/28 22:33:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "MINIRT/world.h"

struct s_mrt_intersection
{
	double						intersection_distance;
	struct s_mrt_world_entry	object;
};

#endif