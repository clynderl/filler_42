/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:02:36 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:38:45 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static int	calc_val(t_board *board, int i, int j)
{
	int	k;
	int	l;
	int	dist;
	int	min_dist;

	min_dist = INT_MAX;
	k = 0;
	while (k < board->height)
	{
		l = 0;
		while (l < board->width)
		{
			if (board->heatmap[k][l] == -2)
			{
				dist = FT_ABS(l - i) + FT_ABS(k - j);
				if (dist < min_dist)
					min_dist = dist;
			}
			l++;
		}
		k++;
	}
	return (min_dist);
}

void		calc_heatmap(t_board *board)
{
	int	j;
	int	i;

	j = 0;
	while (j < board->height)
	{
		i = 0;
		while (i < board->width)
		{
			if (board->heatmap[j][i] == 0)
				board->heatmap[j][i] = calc_val(board, i, j);
			i++;
		}
		j++;
	}
}
