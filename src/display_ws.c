/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:29:40 by sgah              #+#    #+#             */
/*   Updated: 2019/10/28 02:43:51 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>
#include <stdlib.h>

static int		char_len(wchar_t c)
{
	int len;

	if (c <= 127)
		len = 1;
	else if (c >= 127 && c <= 2047)
		len = 2;
	else if (c >= 2048 && c <= 65535)
		len = 3;
	else
		len = 4;
	return (len);
}

static wchar_t	*wstrndup(wchar_t *s1, size_t n, t_tab *tab)
{
	wchar_t	*s2;
	size_t	i;

	i = 0;
	if (!(s2 = (wchar_t *)malloc(sizeof(wchar_t) * n + 1)))
		ERROR(1);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static wchar_t	*wstrdup(wchar_t *str, t_tab *tab)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (wstrndup(str, len, tab));
}

static t_tab	*do_null(t_tab *tab)
{
	wchar_t		*s;
	int			i;

	i = 0;
	if (!(s = wstrdup(L"(null)", tab)))
		IF_ERROR(1, NULL);
	if (tab->precision > -1)
	{
		while (s[i] && tab->precision-- > 0)
			display_wchar(s[i++], tab);
	}
	else
	{
		while (s[i])
			display_wchar(s[i++], tab);
	}
	free(s);
	return (tab);
}

t_tab			*display_ws(t_tab *tab)
{
	wchar_t		*s;
	int			i;
	int			j;
	int			len;

	i = 0;
	len = 0;
	if (!(s = (wchar_t *)va_arg(tab->args, wchar_t *)))
		return (do_null(tab));
	while (s[i] && !(j = 0))
	{
		if (tab->precision > -1 && (len + char_len(s[i])) > tab->precision)
			break ;
		len += char_len(s[i++]);
	}
	if (tab->convert[3] == '0' && tab->convert[0] != '-')
		display_sep(tab, '0', tab->field_width - len, 1);
	else if (tab->convert[0] != '-')
		display_sep(tab, ' ', tab->field_width - len, 1);
	while (j < i)
		display_wchar(s[j++], tab);
	if (tab->convert[0] == '-')
		display_sep(tab, ' ', tab->field_width - len, 1);
	return (tab);
}