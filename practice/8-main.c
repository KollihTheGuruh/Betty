#include <stdio.h>

/**
 * modif_my_char_var - Solve me
 *
 * Return: nothing.
 */
void modif_my_char_var(char *cc, char ccc)  
{
   printf("Before: cc=%p, *cc=%c, ccc=%c\n", cc, *cc, ccc);
   *cc = 'o';
   ccc = 'l';
   printf("After: cc=%p, *cc=%c, ccc=%c\n", cc, *cc, ccc);
}

/**
 * main - Solve me
 *
 * Return: Always 0.
 */
int main(void)
{
   char c;
   char *p;

   p = &c;
   c = 'H';
   printf("Before function call: p=%p, *p=%c, c=%c\n", p, *p, c);
   modif_my_char_var(p, c);
   printf("After function call: p=%p, *p=%c, c=%c\n", p, *p, c);
   return (0);
}
