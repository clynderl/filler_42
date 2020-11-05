/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:04:21 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:04:22 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrs(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (ft_strchr(s, c));
}
