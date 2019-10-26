/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:35:18 by sgah              #+#    #+#             */
/*   Updated: 2019/10/26 14:37:11 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>
# include <ctype.h>
# include "../libft/libft.h"

typedef struct	s_tab
{
	const char	*format;
	char		*copy;
	char		*f_treat;
	va_list		args;
	int			len;
	size_t		i;
	long int	precision;
	long int	field_width;
	char		specifier_flag;
	char		convert[6];
	char		argument_flag[2];
	char		*specifier_list;
	char		*converter_list;
	char		*argument_list;
}				t_tab;

int				ft_printf(const char *format, ...);
int				treatement(t_tab *tab);
int				parser(t_tab *tab);

t_tab			*init(t_tab *tab);
t_tab			*reinit(t_tab *tab);

t_tab			*parse_convert(t_tab *tab);
t_tab			*parse_field_width(t_tab *tab);
t_tab			*parse_precision(t_tab *tab);
t_tab			*parse_arguments(t_tab *tab);
t_tab			*parse_specifier(t_tab *tab);
t_tab			*switch_display(t_tab *tab);

t_tab			*display_d(t_tab *tab);
t_tab			*display_s(t_tab *tab);
t_tab			*display_c(t_tab *tab);
t_tab			*display_u(t_tab *tab);
t_tab			*display_x(t_tab *tab);
t_tab			*display_o(t_tab *tab);
t_tab			*display_p(t_tab *tab);
t_tab			*display_ws(t_tab *tab);
t_tab			*display_other(t_tab *tab);
void			display_wchar(wint_t c, t_tab *tab);
void			display_gap(t_tab *tab, char c, int len, int update_len);

#endif