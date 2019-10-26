/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:02:31 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:02:34 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*reinit(t_tab *tab)
{
	tab->specifier_flag = '\0';
	tab->convert[0] = '\0';
	tab->convert[1] = '\0';
	tab->convert[2] = '\0';
	tab->convert[3] = '\0';
	tab->convert[4] = '\0';
	tab->convert[5] = '\0';
	tab->argument_flag[0] = '\0';
	tab->argument_flag[1] = '\0';
	tab->precision = -1;
	tab->field_width = 0;
	return (tab);
}
