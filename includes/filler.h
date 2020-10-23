/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:59:46 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:22:56 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef	struct	s_board
{
	int			width;
	int			height;
	int			**heatmap;
	char		**map;
}				t_board;

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;


typedef	struct s_filler
{
	t_board		*board;
	t_board		*piece;
	int			x;
	int			y;
}				t_filler;


t_filler	*init_filler(void);
int			parse_player();
t_board		*init_board(void);
t_board		*init_piece(void);
int			**init_heatmap(int h, int w);
char		parse_player_char(int player);
char		parse_enemy_char(int player);
int			parse_board(t_board *board, int player);
int			parse_piece(t_board *piece);
void		calc_heatmap(t_board *board);
void		put_piece(t_board *board, t_board *piece, t_filler *filler);
void		free_board(t_board **board);
void		free_piece(t_board **piece);
void		reset_coords(t_filler *filler);

#endif
