/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 10:59:46 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/13 13:21:53 by clynderl         ###   ########.fr       */
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
	t_point		coordinates;
}				t_filler;



#endif
