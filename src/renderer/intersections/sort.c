/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kisikogl <kisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:06:39 by htsang            #+#    #+#             */
/*   Updated: 2023/09/09 08:43:13 by kisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MINIRT/renderer.h"

static void	mrt_intersections_sort_swap(struct s_mrt_intersection **a, \
struct s_mrt_intersection **b)
{
	struct s_mrt_intersection	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// Partition function for QuickSort
static int	mrt_intersections_sort_partition(struct s_mrt_intersection **array, \
int low, int high)
{
	double	pivot;
	int		i;
	int		j;

	pivot = array[high]->time;
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j]->time < pivot)
		{
			i++;
			mrt_intersections_sort_swap(&array[i], &array[j]);
		}
		j++;
	}
	mrt_intersections_sort_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * @brief Sorts intersections by time, using the quicksort algorithm
*/
static void	mrt_intersections_sort_internal(struct s_mrt_intersection **array, \
int low, int high)
{
	int	pivot_element;

	if (low < high)
	{
		pivot_element = mrt_intersections_sort_partition(array, low, high);
		mrt_intersections_sort_internal(array, low, pivot_element - 1);
		mrt_intersections_sort_internal(array, pivot_element + 1, high);
	}
}

void	mrt_intersections_sort(t_mrt_intersections *intersections)
{
	if (intersections->size)
	{
		mrt_intersections_sort_internal((struct s_mrt_intersection **) \
			intersections->buffer, 0, intersections->size - 1);
	}
}
