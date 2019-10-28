/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 21:34:03 by sgah              #+#    #+#             */
/*   Updated: 2019/10/28 01:18:35 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    display_b(t_tab *tab)
{
    intmax_t b;
    intmax_t c;
    int i;

    b = (intmax_t)(va_arg(tab->args, intmax_t));
    c = b;
    i = 1;
    while (c /= 2)
        i++;
    while (i-- && (tab->len += 1))
        ((b >> i) & 1) ? write(1, "1", 1) : write(1, "0", 1);
}