/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:33:02 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/13 14:54:19 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parse_player()
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if (get_next_line(0, &line) != 1 && ft_strstr(line, "$$$ exec")
			&& ft_strstr(line, "clynderl.filler"))
	{
		if (ft_strstr(line, "p1"))
			ret = 1;
		else if (ft_strstr(line, "p2"))
			ret = 2;
	}
	ft_memdel(&line);
	return (ret);
}

int		parse_board_size(t_board *board, char *word)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if (get_next_line(0, &line) && ft_strstr(line, word))
		if (ft_strchr(line, ' ') && ft_strrchr(line, ' '))
		{
			board->height = ft_atoi(ft_strchr(line, ' '));
			board->width = ft_atoi(ft_strrchr(line, ' '));
			ret = 1;
		}
	ft_strdel(&line);
	return(ret);
}

int		parse_board(t_board *board)
{
	if (!get_board_info(board, "Plateau"))
		return (0);
}
