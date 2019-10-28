/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:25:33 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 14:30:11 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
 
t_tab			*display_s(t_tab *tab)
{
	char		*s;
	int			len;

	s = va_arg(tab->args, char *);
	if (tab->precision > -1 && s)
		s = ft_strndup(s, tab->precision);
	else if (tab->precision == -1 && s)
		s = ft_strdup(s);
	else if (tab->precision > -1 && !s)
		s = ft_strndup("(null)", tab->precision);
	else if (tab->precision == -1 && !s)
		s = ft_strdup("(null)");
	len = ft_strlen(s);
	tab->len += len;
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		display_sep(tab, '0', tab->field_width - len, 1);
	else if (tab->convert[0] != '-')
		display_sep(tab, ' ', tab->field_width - len, 1);
	ft_putstr(s);
	if (tab->convert[0] == '-')
		display_sep(tab, ' ', tab->field_width - len, 1);
	free(s);
	return (tab);
}