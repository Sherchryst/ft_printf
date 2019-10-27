/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 19:19:00 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 01:28:39 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char		*dup;
	size_t		i;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(char *) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1 && s1[i])
	{
		dup[i] = ((char *)s1)[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
