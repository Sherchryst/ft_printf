/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:35:18 by sgah              #+#    #+#             */
/*   Updated: 2019/10/28 02:40:16 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <wchar.h>
# include <stdarg.h>
# include <ctype.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define ERROR(n) if((tab->error = n)) return NULL
# define IF_ERROR(n, ret) if(tab->error == n) return (ret)
# define ERROR_V(n) if((tab->error = n)) return

typedef struct		s_tab
{
	const char		*format;
	char			*copy;
	char			*f_treat;
	va_list			args;
	int				len;
	size_t			i;
	char			*specifier_list;
	char			*converter_list;
	char			*argument_list;
	long int		precision;
	long int		field_width;
	char			specifier_flag;
	char			convert[6];
	char			argument_flag[2];
	int				error;
}					t_tab;

int					ft_printf(const char *format, ...);
int					treatement(t_tab *tab);
int					parser(t_tab *tab);

t_tab				*init(t_tab *tab);
t_tab				*reinit(t_tab *tab);

t_tab				*parse_convert(t_tab *tab);
t_tab				*parse_field_width(t_tab *tab);
t_tab				*parse_precision(t_tab *tab);
t_tab				*parse_arguments(t_tab *tab);
t_tab				*parse_specifier(t_tab *tab);
t_tab				*switch_display(t_tab *tab);

t_tab				*display_d(t_tab *tab);
t_tab				*display_s(t_tab *tab);
t_tab				*display_c(t_tab *tab);
t_tab				*display_u(t_tab *tab);
t_tab				*display_x(t_tab *tab);
t_tab				*display_o(t_tab *tab);
t_tab				*display_p(t_tab *tab);
t_tab				*display_ws(t_tab *tab);
t_tab				*display_other(t_tab *tab);
void				display_b(t_tab *tab);
void				display_wchar(wint_t c, t_tab *tab);
void				display_sep(t_tab *tab, char c, int len, int update_len);

void				ft_putnbrmax_fd(intmax_t n, int fd);
void				ft_putstr(char const *s);
void				ft_putnbrumax_fd(uintmax_t n, int fd);
char				*ft_itoa_base(uintmax_t num, uintmax_t base, char c);
char				*ft_strnew(size_t size);
char				*ft_strndup(const char *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_putchar_fd(char c, int fd);

#endif