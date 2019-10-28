/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:52:57 by sgah              #+#    #+#             */
/*   Updated: 2019/10/28 02:40:16 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int			ft_printf(const char *format, ...)
{
	t_tab	*tab;
	int		len;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	tab = init(tab);
	if (format)
	{
		va_start(tab->args, format);
		tab->len = parser(tab);
		IF_ERROR(1, -1);
		va_end(tab->args);
	}
	len = tab->len;
	free(tab);
	return (len);
}
