/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:23:40 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 14:30:11 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static t_tab	*display_percent(t_tab *tab)
{
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		tab->field_width = 0;
	}
	if (tab->convert[0] != '-')
		display_sep(tab, ' ', tab->field_width - 1, 1);
	if (tab->convert[3] == '0')
		display_sep(tab, '0', tab->precision - 1, 1);
	write(1, "%", 1);
	if (tab->convert[0] == '-')
		display_sep(tab, ' ', tab->field_width - 1, 1);
	tab->len++;
	return (tab);
}

t_tab			*display_other(t_tab *tab)
{
	if (tab->f_treat[tab->i] == '%')
	{
		display_percent(tab);
		return (tab);
	}
	if (tab->convert[3] == '0' && tab->precision <= 0 && !tab->convert[0])
	{
		tab->precision = tab->field_width;
		tab->field_width = 0;
	}
	if (tab->convert[0] != '-')
		display_sep(tab, ' ', tab->field_width - 1, 1);
	if (tab->convert[3] == '0')
		display_sep(tab, '0', tab->precision - 1, 1);
	write(1, &tab->copy[tab->i], 1);
	if (tab->convert[0] == '-')
		display_sep(tab, ' ', tab->field_width - 1, 1);
	tab->len++;
	return (tab);
}