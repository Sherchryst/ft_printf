/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:05:38 by sgah              #+#    #+#             */
/*   Updated: 2019/10/01 18:05:41 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int		treatement(t_tab *tab)
{
	tab->i++;
	parse_convert(tab);
	parse_field_width(tab);
	parse_precision(tab);
	parse_arguments(tab);
	parse_specifier(tab);
	switch_display(tab);
	return (tab->len);
}
