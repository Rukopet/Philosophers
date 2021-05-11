/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egums <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:09:10 by egums             #+#    #+#             */
/*   Updated: 2020/11/01 16:56:13 by egums            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*res;
	int	i;

	len = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * ++len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i != len)
		res[i] = s1[i];
	return (res);
}
