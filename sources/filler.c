/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:59:23 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/13 13:24:09 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*filler;

	if (!(filler = init_filler())|| !(parse_player(filler)))
		return (0);
	if (!(filler->board = init_board()) || !(filler->piece = init_piece()))
			return (0);
}
