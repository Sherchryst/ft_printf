/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:55:49 by sgah              #+#    #+#             */
/*   Updated: 2019/10/28 02:46:15 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void			print_format(t_tab *tab, int count)
{
	char			*format;

	format = NULL;
	if (!count || count < 0)
		return ;
	if (!(format = ft_strndup((tab->copy + (tab->i - count)), count)))
		ERROR_V(1);
	ft_putstr(format);
	free(format);
	format = NULL;
}

int					parser(t_tab *tab)
{
	int				count;

	count = 0;
	if (ft_strcmp(tab->copy, "%") == 0)
		return (0);
	while (tab->copy[tab->i] != '\0')
	{
		if (tab->copy[tab->i] == '%')
		{
			print_format(tab, count);
			IF_ERROR(1, -1);
			reinit(tab);
			treatement(tab);
			IF_ERROR(1, -1);
			count = 0;
		}
		else
		{
			count++;
			tab->len++;
		}
		tab->i++;
	}
	print_format(tab, count);
	return (tab->len);
}
