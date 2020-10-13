/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:33:02 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/13 13:38:34 by clynderl         ###   ########.fr       */
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
