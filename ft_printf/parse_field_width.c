/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_field_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:11:03 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:11:04 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_field_width(t_tab *tab)
{
	while (tab->f_treat[tab->i] >= '0' && tab->f_treat[tab->i] <= '9')
	{
		tab->field_width *= 10;
		tab->field_width += (tab->f_treat[tab->i] - 48);
		tab->i++;
	}
	return (tab);
}
