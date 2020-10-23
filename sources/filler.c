/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:59:23 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:28:48 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "ft_printf.h"

int		main(void)
{
	t_filler	*filler;
	int			player;

	if (!(filler = init_filler())
	|| !(player = parse_player()))
		return (0);
	while ((filler->board = init_board())
	&& (filler->piece = init_piece()))
	{
		if (!(parse_board(filler->board, player))
		|| !(parse_piece(filler->piece)))
			return (0);
		calc_heatmap(filler->board);
		put_piece(filler->board, filler->piece, filler);
		ft_printf("%d %d\n", filler->x, filler->y);
		free_board(&(filler->board));
		free_piece(&(filler->piece));
		reset_coords(filler);
	}
	return (0);
}
