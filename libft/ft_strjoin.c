/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:53:07 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/29 07:43:03 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_result;
	size_t	size_s1;
	size_t	size_s2;
	char	*result;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size_result = size_s1 + size_s2;
	result = ft_strnew(size_result);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcpy((result + size_s1), s2);
	return (result);
}
