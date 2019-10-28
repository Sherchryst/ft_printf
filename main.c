/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:08:22 by sgah              #+#    #+#             */
/*   Updated: 2019/10/28 02:01:48 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "get_next_line c'était chiant";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};

  printf("##### Tests Basic #####\n");
  printf(   ">> Caractere [c] : {%c}\n", 42);
  ft_printf("=> Caractere [c] : {%c}\n", 42);
  printf(   ">> Chaine [s] : {%s}\n", str);
  ft_printf("=> Chaine [s] : {%s}\n", str);
  printf(   ">> Pointeur [p] : {%p}\n", str);
  ft_printf("=> Pointeur [p] : {%p}\n", str);
  printf(   ">> Nombre signe [d] : {%d}\n", 42);
  ft_printf("=> Nombre signe [d] : {%d}\n", 42);
  printf(   ">> Nombre signe [i] : {%i}\n", 42);
  ft_printf("=> Nombre signe [i] : {%i}\n", 42);
  printf(   ">> Nombre non signe [u] : {%u}\n", 42);
  ft_printf("=> Nombre non signe [u] : {%u}\n", 42);
  printf(   ">> Nombre hexadecimal [x] : {%x}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
  printf(   ">> Nombre hexadecimal [X] : {%X}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
  printf(   ">> Modulo [%%] : {%%}\n");
  ft_printf("=> Modulo [%%] : {%%}\n");
  printf(   ">> Mauvais parametre [k] : {%k}\n", 42);
  ft_printf("=> Mauvais parametre [k] : {%k}\n", 42);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("##### Tests Basic complexe#####\n");
  printf(   ">> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  printf(   ">> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483648);
  printf(   ">> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  ft_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  printf(   ">> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  ft_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  printf(   ">> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  ft_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);

  
  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests Formatage #####\n");
  printf(   ">> Formatage simple [#d] : {%#d}\n", 42);
  ft_printf("=> Formatage simple [#d] : {%#d}\n", 42);
  printf(   ">> Formatage simple [#x] : {%#x}\n", 0x12345);
  ft_printf("=> Formatage simple [#x] : {%#x}\n", 0x12345);
  printf(   ">> Formatage simple [#o] : {%#o}\n", 012345);
  ft_printf("=> Formatage simple [#o] : {%#o}\n", 012345);
  printf(   ">> Formatage simple [0d] : {%0d}\n", 42);
  ft_printf("=> Formatage simple [0d] : {%0d}\n", 42);
  printf(   ">> Formatage simple [5d] : {%5d}\n", 42);
  ft_printf("=> Formatage simple [5d] : {%5d}\n", 42);
  printf(   ">> Formatage simple [ d] : {% d}\n", 42);
  ft_printf("=> Formatage simple [ d] : {% d}\n", 42);
  printf(   ">> Formatage simple [-d] : {%-d}\n", 42);
  ft_printf("=> Formatage simple [-d] : {%-d}\n", 42);
  printf(   ">> Formatage multiple [ 5d] : {% 5d}\n", 42);
  ft_printf("=> Formatage multiple [ 5d] : {% 5d}\n", 42);
  printf(   ">> Formatage compose [-30sP]: %-30sP\n", str);
  ft_printf("=> Formatage compose [-30sP]: %-30sP\n", str);
  printf(   ">> Formatage pourcent [30%%] : {%30%}\n");
  ft_printf("=> Formatage pourcent [30%%] : {%30%}\n");
  printf(   ">> Formatage pourcent [-30%%] : {%-30%}\n");
  ft_printf("=> Formatage pourcent [-30%%] : {%-30%}\n");

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("##### Tests BONUS#####\n");
  printf(   ">> Nombre binaire [b] : {101111101111110000001}\n");
  ft_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
  printf(   ">> Nombre octal [o] : {%o}\n", 012345);
  ft_printf("=> Nombre octal [o] : {%o}\n", 012345);
  printf(   ">> Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);
  ft_printf("=> Test de pile [c c] : {%c} {%c}\n", 0x4142434444434241);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests BONUS Formatage #####\n");
  printf(   ">> Formatage simple [+d] : {%+d}\n", 42);
  ft_printf("=> Formatage simple [+d] : {%+d}\n", 42);
  printf(   ">> Formatage simple [+d] : {%+d}\n", -42);
  ft_printf("=> Formatage simple [+d] : {%+d}\n", -42);
  printf(   ">> Formatage multiple [-10+d] : {%-+10d}\n", 12345);
  ft_printf("=> Formatage multiple [-10+d] : {%-+10d}\n", 12345);
  printf(   ">> Formatage multiple [-32o] : {%-32o}\n", 012345);
  ft_printf("=> Formatage multiple [-32o] : {%-32o}\n", 012345);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests qui tue #####\n");
  printf(   ">> Formatage multiple [-32o] : {%-32o}\n", 012345);
  ft_printf("=> Formatage multiple [-32o] : {%-32o}\n", 012345);
  printf(   ">> Formatage compose [-5cP] : %-5cP\n", 42);
  ft_printf("=> Formatage compose [-5cP] : %-5cP\n", 42);
 
  printf(   ">> Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  ft_printf("=> Formatage ultracompose [-6.3x] : {%-6.3x}\n", 0x12345);
  printf(   ">> Formatage ultracompose [#15.12b] : {101111101111110000001}\n");
  ft_printf("=> Formatage ultracompose [#15.12b] : {%#15.12b}\n", 1564545);
  printf(   ">> Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  ft_printf("=> Formatage ultracompose [#-6.3d] : {%#-6.3d}\n", -2147483648);
  printf(   ">> Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  ft_printf("=> Formatage long [p x lx] : {%p} {%x} {%lx}\n", 0x42424242, 0x42424242, 0x42424242);
  ret[0] = printf(   ">> Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  ret[1] = ft_printf("=> Test de la valeur de retour [-10+d s] : {%+-10d} {%s}\n", 12345, str);
  printf(   ">> Verification de la valeur de retour [d] : {%d}\n", ret[0]);
  ft_printf("=> Verification de la valeur de retour [d] : {%d}\n", ret[1]);
 
  printf("Appuyez sur une touche pour continuer...\n");
  getchar();
//petit Troll
  ft_printf("Segmentation fault ;)\n");

  return(0);
}
