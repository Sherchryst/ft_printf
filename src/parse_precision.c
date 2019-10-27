/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:12:14 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:12:16 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_precision(t_tab *tab)
{
	while (tab->f_treat[tab->i] == '.')
	{
		tab->i++;
		tab->precision = 0;
	}
	while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
	{
		tab->precision *= 10;
		tab->precision += (tab->f_treat[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}