/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:54:10 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 17:54:12 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*init(t_tab *tab)
{
	tab->len = 0;
	tab->i = 0;
	tab->specifier_list = "scSCdDiuUoOxXbp%";
	tab->converter_list = "-+ 0#";
	tab->argument_list = "lhjz";
	tab->f_treat = (char *)tab->format;
	tab->copy = (char *)tab->format;
	return (tab);
}
