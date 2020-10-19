/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:59:23 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/19 20:43:51 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static void	print_result(t_filler *filler)
{
	ft_log('X');
	ft_log_int(filler->x);
	ft_log('Y');
	ft_log_int(filler->y);
	printf("%d %d\n", filler->y, filler->x);
	ft_log('Z');
}
int		ft_log(char c)
{
	FILE *fp;
	fp = fopen("output", "a+");
	fprintf (fp,"%c", c);
	fclose(fp);
}
int		ft_log_int(int i)
{
	FILE *fp;
	fp = fopen("output", "a+");
	fprintf (fp,"%d", i);
	fclose(fp);
}

int		main(void)
{
	t_filler	*filler;
	int			player;

	if (!(filler = init_filler())|| !(player = parse_player()))
		return (0);
	while ((filler->board = init_board()) && (filler->piece = init_piece()))
	{
		if (!parse_board(filler->board, player) || !parse_piece(filler->piece))
			return (0);
		calc_heatmap(filler->board);
		put_piece(filler->board, filler->piece, filler);
		printf("%d %d\n",filler->x, filler->y);
		free_board(&(filler->board));
		free_piece(&(filler->piece));
		reset_coords(filler);;
	}
	return (0);
}
