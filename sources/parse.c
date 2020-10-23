/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:33:02 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:38:28 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			parse_player(void)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if (get_next_line(0, &line) && ft_strstr(line, "$$$ exec")
			&& ft_strstr(line, "clynderl.filler"))
	{
		if (ft_strstr(line, "p1"))
			ret = 1;
		else if (ft_strstr(line, "p2"))
			ret = 2;
	}
	ft_memdel((void**)&line);
	return (ret);
}

static int	parse_board_size(t_board *board, char *word)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if (get_next_line(0, &line) && (ft_strstr(line, word)))
		if (ft_strchr(line, ' ') && ft_strrchr(line, ' '))
		{
			board->height = ft_atoi(ft_strchr(line, ' '));
			board->width = ft_atoi(ft_strrchr(line, ' '));
			ret = 1;
		}
	ft_strdel(&line);
	return (ret);
}

int			parse_board_line(char *line, int *board_line, int width, int player)
{
	int		i;

	i = 0;
	while (i < width)
	{
		if (line[i] == '.')
			board_line[i] = 0;
		else if (ft_toupper(line[i]) == (player == 1 ? 'O' : 'X'))
			board_line[i] = -1;
		else if (ft_toupper(line[i]) == (player == 2 ? 'O' : 'X'))
			board_line[i] = -2;
		else
			return (0);
		i++;
	}
	return (1);
}

int			parse_board(t_board *board, int player)
{
	char	*line;
	int		j;

	if (!parse_board_size(board, "Plateau") ||
	!(board->heatmap = init_heatmap(board->height, board->width)))
		return (0);
	if (!get_next_line(0, &line))
		return (0);
	ft_strdel(&line);
	j = 0;
	while (j < board->height)
	{
		if (!get_next_line(0, &line)
			|| !parse_board_line(&line[4],
			board->heatmap[j], board->width, player))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
		j++;
	}
	return (1);
}

int			parse_piece(t_board *piece)
{
	char	*line;
	int		i;

	i = 0;
	if (!parse_board_size(piece, "Piece"))
		return (0);
	if (!(piece->map = (char **)ft_memalloc(sizeof(char *) * piece->height)))
		return (0);
	while (i < piece->height)
	{
		if (!(piece->map[i] = ft_strnew(piece->width)))
			return (0);
		if (get_next_line(0, &line))
		{
			ft_strncpy(piece->map[i], line, piece->width);
			ft_strdel(&line);
		}
		i++;
	}
	return (1);
}
