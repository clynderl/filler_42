/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:21:34 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:39:08 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static int	calc_piece(t_board *bd, t_board *piece, int k, int l)
{
	int	i;
	int	j;
	int	fl;
	int	val;

	i = -1;
	fl = 0;
	val = 0;
	while (++i < piece->height)
	{
		j = -1;
		while (++j < piece->width)
		{
			if (piece->map[i][j] == '*')
			{
				if ((k + i) < 0 || (k + i) >= bd->height || (l + j) < 0
				|| (l + j) >= bd->width || bd->heatmap[k + i][l + j] == -2)
					return (-1);
				if (bd->heatmap[k + i][l + j] == -1)
					fl++;
				val += bd->heatmap[k + i][l + j];
			}
		}
	}
	return (fl == 1 ? val : -1);
}

void		put_piece(t_board *board, t_board *piece, t_filler *filler)
{
	int	i;
	int	j;
	int	tmp;
	int	val;

	tmp = INT_MAX;
	i = -piece->height + 1;
	while (i < board->height + piece->height)
	{
		j = -piece->width + 1;
		while (j < board->width + piece->width)
		{
			val = calc_piece(board, piece, i, j);
			if (val != -1 && val < tmp)
			{
				filler->x = i;
				filler->y = j;
				tmp = val;
			}
			j++;
		}
		i++;
	}
}
