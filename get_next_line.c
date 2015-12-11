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

int				get_next_line(int const fd, char **line)
{
	static char		*cache;
	char			buffer[BUFF_SIZE + 1];
	int				ret;

	ret = 1;
	if (!line || BUFF_SIZE <= 0)
		return (-1);
	if (!cache)
		cache = ft_strnew(0);
	while (!ft_strchr(cache, '\n') && (ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		*(buffer + ret) = '\0';
		cache = ft_strjoin(cache, buffer);
	}
	if (ft_strchr(cache, '\n') || ((*line = ft_strdup(cache)) && 0))
			*line = ft_strsub(cache, 0, ft_strchr(cache, '\n') - cache + 1);
	if (ret)
		*(*(line) + ft_strlen(*line) - 1) = '\0';
	cache = ft_strsub(cache, ft_strchr(cache, '\n') - cache + 1, ft_strlen(ft_strchr(cache, '\n')));
	return (ret > 0 ? 1 : 0);
}
