/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:11:37 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/29 08:50:55 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int					get_next_line(int const fd, char **line);

typedef struct		s_buff
{
	int				fd;
	char			*buff;
	struct s_buff	*next;
}					t_buff;

#endif
