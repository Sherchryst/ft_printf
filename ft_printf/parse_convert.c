/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:07:06 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:07:09 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*parse_convert(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->converter_list[i] != '\0')
	{
		while (tab->converter_list[i] == tab->f_treat[tab->i])
		{
			while (tab->f_treat[tab->i] == '-' && tab->i++)
				tab->convert[0] = '-';
			while (tab->f_treat[tab->i] == '+' && tab->i++)
				tab->convert[1] = '+';
			while (tab->f_treat[tab->i] == ' ' && tab->i++)
				tab->convert[2] = ' ';
			while (tab->f_treat[tab->i] == '0' && tab->i++)
				tab->convert[3] = '0';
			while (tab->f_treat[tab->i] == '#' && tab->i++)
				tab->convert[4] = '#';
			i = 0;
		}
		i++;
	}
	return (tab);
}
