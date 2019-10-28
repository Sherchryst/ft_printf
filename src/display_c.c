/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:19:53 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 16:43:20 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

t_tab		*display_c(t_tab *tab)
{
	wint_t		c;

	if (ft_strcmp(tab->argument_flag, "l") == 0)
		c = (unsigned long)va_arg(tab->args, unsigned long);
	else if (tab->specifier_flag == 'C')
		c = (wchar_t)va_arg(tab->args, wint_t);
	else
		c = (char)va_arg(tab->args, int);
	c = (wint_t)c;
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		display_sep(tab, '0', tab->field_width - 1, 1);
	else if (tab->convert[0] != '-')
		display_sep(tab, ' ', tab->field_width - 1, 1);
	display_wchar(c, tab);
	if (tab->convert[0] == '-')
		display_sep(tab, ' ', tab->field_width - 1, 1);
	return (tab);
}
