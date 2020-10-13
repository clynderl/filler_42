/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:59:23 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/13 15:01:19 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*filler;
	int			player;

	if (!(filler = init_filler())|| !(player = parse_player()))
		return (0);
	if (!(filler->board = init_board()) || !(filler->piece = init_piece()))
			return (0);
	while (1)
	{
		if (!parse_board(filler->board) || !parse_piece(filler->piece))
			return (0);
	}

}
