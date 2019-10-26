/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:13:15 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:14:12 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*parse_arguments(t_tab *tab)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tab->argument_list[i] != '\0')
	{
		while (tab->argument_list[i] == tab->f_treat[tab->i])
		{
			tab->argument_flag[j] = tab->f_treat[tab->i];
			tab->argument_flag[j + 1] = '\0';
			tab->i++;
			j++;
		}
		i++;
	}
	return (tab);
}