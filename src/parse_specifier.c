/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:15:16 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:15:18 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_specifier(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->specifier_list[i] != '\0')
	{
		if (tab->specifier_list[i] == tab->f_treat[tab->i])
			tab->specifier_flag = tab->specifier_list[i];
		i++;
	}
	return (tab);
}