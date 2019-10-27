/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:17:43 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 01:32:03 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*switch_display(t_tab *tab)
{
	char	*flag;

	flag = &tab->specifier_flag;
	if (*flag == 'd' || *flag == 'i' || *flag == 'D')
		display_d(tab);
	else if (*flag == 'c' || *flag == 'C')
		display_c(tab);
	else if (*flag == 's' && ft_strcmp(tab->argument_flag, "l") == 0)
		display_ws(tab);
	else if (*flag == 's')
		display_s(tab);
	else if (*flag == 'S')
		display_ws(tab);
	else if (*flag == 'u' || *flag == 'U')
		display_u(tab);
	else if (*flag == 'x' || *flag == 'X')
		display_x(tab);
	else if (*flag == 'o' || *flag == 'O')
		display_o(tab);
	else if (*flag == 'p')
		display_p(tab);
	else
		display_other(tab);
	return (tab);
}