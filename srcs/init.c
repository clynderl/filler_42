/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:09:47 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:30:32 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init_filler(void)
{
	t_filler	*filler;

	if ((filler = (t_filler *)ft_memalloc(sizeof(t_filler))))
	{
		filler->board = NULL;
		filler->piece = NULL;
	}
	return (filler);
}

t_board		*init_board(void)
{
	t_board		*board;

	if ((board = (t_board *)ft_memalloc(sizeof(t_board))))
	{
		board->height = 0;
		board->width = 0;
		board->heatmap = NULL;
		board->map = NULL;
	}
	return (board);
}

t_board		*init_piece(void)
{
	t_board		*piece;

	if ((piece = (t_board *)ft_memalloc(sizeof(t_board))))
	{
		piece->height = 0;
		piece->width = 0;
		piece->heatmap = NULL;
		piece->map = NULL;
	}
	return (piece);
}

int			**init_heatmap(int h, int w)
{
	int		**arr;
	int		j;

	j = 0;
	if ((arr = (int **)ft_memalloc(sizeof(int *) * h)))
	{
		while (j < h)
		{
			if (!(arr[j] = (int *)ft_memalloc(sizeof(int) * w)))
			{
				while (--j >= 0)
					free(arr[j]);
				free(arr);
				return (NULL);
			}
			j++;
		}
	}
	return (arr);
}
