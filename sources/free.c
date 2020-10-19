/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:00:29 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/19 18:34:07 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_board(t_board **board)
{
	int i;

	i = 0;
	while (i < (*board)->height)
	{
		free((*board)->heatmap[i]);
		i++;
	}
	free((*board)->heatmap);
	free((*board));
	(*board) = NULL;
}

void	free_piece(t_board **piece)
{
	int i;

	i = 0;
	while (i < (*piece)->height)
	{
		free((*piece)->map[i]);
		i++;
	}
	free((*piece)->map);
	free((*piece));
	(*piece) = NULL;
}

void	reset_coords(t_filler *filler)
{
	filler->y = 0;
	filler->x = 0;
}
