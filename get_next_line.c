/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:02:41 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/11 16:23:12 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strrealloc(char *prev, size_t new_size)
{
	char	*result;

	if (!(result = ft_strnew(new_size)))
		return (0);
	ft_strncpy(result, prev, ft_strlen(prev));
	free(prev);
	prev = result;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char			*buffer = NULL;
	static int			prev_pos = 0;
	char				*tmp;
	int					i;

	i = 0;
	if ((!buffer && !(buffer = ft_strnew(BUFF_SIZE))) ||
			(prev_pos && !(ft_strrealloc(buffer, BUFF_SIZE + prev_pos))))
		return (-1);
	while ((i = read(fd, (buffer + prev_pos), BUFF_SIZE) > 0))
	{
		if ((tmp = ft_strchr(buffer, '\n')) || (tmp = ft_strchr(buffer, -1)))
		{
			*line = ft_strncpy(*line, buffer, (tmp - buffer));
			prev_pos = (i < BUFF_SIZE) ? i : 0;
			return (1);
		}
	}
	return (0);
}
