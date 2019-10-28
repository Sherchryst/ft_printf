/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:24:43 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 15:52:12 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static uintmax_t	get_num(t_tab *tab)
{
	uintmax_t	num;

	num = (unsigned long)(va_arg(tab->args, unsigned long int));
	num = (uintmax_t)num;
	return (num);
}

static t_tab		*print_u(t_tab *tab, char *str, int align_left)
{
	int			not_blank;
	int			num_width;

	num_width = ft_strlen(str) + 2;
	not_blank = num_width;
	tab->len += (not_blank <= tab->field_width) ? tab->field_width : not_blank;
	if (!align_left)
		display_sep(tab, ' ', tab->field_width - not_blank, 0);
	write(1, "0x", 2);
	display_sep(tab, '0', (tab->precision - num_width) + 2, 1);
	ft_putstr(str);
	if (align_left)
		display_sep(tab, ' ', tab->field_width - not_blank, 0);
	free(str);
	return (tab);
}

t_tab				*display_p(t_tab *tab)
{
	char		*str;
	uintmax_t	num;
	int			align_left;

	align_left = 0;
	num = get_num(tab);
	if (!(str = ft_itoa_base(num, 16, 'a')))
		ERROR(1);
	if (tab->convert[0] == '-')
		align_left = 1;
	if (tab->precision == 0 && num == 0)
		*str = '\0';
	if (tab->convert[3] == '0' && tab->precision == -1 && !tab->convert[0])
	{
		tab->precision = tab->field_width - 2;
		tab->field_width = 0;
	}
	print_u(tab, str, align_left);
	return (tab);
}