#include <stdio.h>
#include "includes/ft_printf.h"

int	main(int ac, char **av)
{
  int	ret[2];
  char	*str = "astek";
  char	stre[] = {'a', 's', 10, 'e', 'k', 0};

  int n = printf("salut%s\n", str);
  int n1 = ft_printf("salut%s\n", str);

  printf("ft = %d, pr = %d\n", n1, n);

  printf("##### Tests simple : 1 point par test reussi #####\n");
  printf(   "0) Modulo [%%] : {%%}\n");
  ft_printf("=> Modulo [%%] : {%%}\n");
  printf(   "1) Nombre signe [d] : {%d}\n", 42);
  ft_printf("=> Nombre signe [d] : {%d}\n", 42);
  printf(   "2) Nombre signe [i] : {%i}\n", 42);
  ft_printf("=> Nombre signe [i] : {%i}\n", 42);
  printf(   "3) Nombre octal [o] : {%o}\n", 012345);
  ft_printf("=> Nombre octal [o] : {%o}\n", 012345);
  printf(   "4) Nombre non signe [u] : {%u}\n", 42);
  ft_printf("=> Nombre non signe [u] : {%u}\n", 42);
  printf(   "5) Nombre hexadecimal [x] : {%x}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [x] : {%x}\n", 0x12345);
  printf(   "6) Nombre hexadecimal [X] : {%X}\n", 0x12345);
  ft_printf("=> Nombre hexadecimal [X] : {%X}\n", 0x12345);
  printf(   "7) Nombre binaire [b] : {101111101111110000001}\n");
  ft_printf("=> Nombre binaire [b] : {%b}\n", 1564545);
  printf(   "8) Caractere [c] : {%c}\n", 42);
  ft_printf("=> Caractere [c] : {%c}\n", 42);
  printf(   "9) Chaine [s] : {%s}\n", str);
  ft_printf("=> Chaine [s] : {%s}\n", str);
  printf(   "10) Chaine etendue [S] : as\\012ek\n");
  ft_printf("=>  Chaine etendue [S] : %S\n", stre);
  printf(   "11) Pointeur [p] : {%p}\n", str);
  ft_printf("=>  Pointeur [p] : {%p}\n", str);
  //printf(   "12) Mauvais parametre [k] : {%k}\n", 42);
  //ft_printf("=>  Mauvais parametre [k] : {%k}\n", 42);

  printf("Appuyez sur [entree] pour continuer...\n");
  getchar();

  printf("\n##### Tests pour verifier : -1pt par resultat errone #####\n");
  printf(   "1) Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", 0, 42, 2147483647);
  printf(   "2) Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483647);
  ft_printf("=> Affichage multiple [d d d] : {%d} {%d} {%d}\n", -0, -42, -2147483647);
  printf(   "3) Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  ft_printf("=> Affichage multiple [c d s] : {%c} {%d} {%s}\n", 42, 42, str);
  printf(   "4) Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  ft_printf("=> Affichage multiple [X p d] : {%X} {%p} {%d}\n", 0x12345, str, 42);
  printf(   "5) Affichage multiple [s S X] : {%s} {as\\012ek} {%x} {%X}\n", str, 42, -42);
  ft_printf("=> Affichage multiple [s S X] : {%s} {%S} {%x} {%X}\n", str, stre, 42, -42);
  printf(   "5) Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  ft_printf("=> Affichage long [d d d ...] : %d %d %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC);
  printf(   "6) Affichage long [s S s ...] : %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek %s as\\012ek\n", str, str, str, str, str, str);
  ft_printf("=> Affichage long [s S s ...] : %s %S %s %S %s %S %s %S %s %S %s %S\n", str, stre, str, stre, str, stre, str, stre, str, stre, str, stre);

  printf("Appuyez sur une touche pour continuer...\n");
  getchar();

  return(0);
}
