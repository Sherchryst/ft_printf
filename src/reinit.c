/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:02:31 by sgah              #+#    #+#             */
/*   Updated: 2019/10/27 02:23:58 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*reinit(t_tab *tab)
{
	int	i;

	i = 0;
	tab->specifier_flag = '\0';
	while (i < 6)
		tab->convert[i++] = '\0';
	tab->argument_flag[0] = '\0';
	tab->argument_flag[1] = '\0';
	tab->precision = -1;
	tab->field_width = 0;
	return (tab);
}
