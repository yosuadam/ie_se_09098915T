#include "leon3_bprint.h"

int8_t leon3_print_string(char* str)
{
	uint32_t e = 0;
	int i = 0;
//Todo bien. El tratamiento de errores añadido
	while (str[i] != '\0' && e == 0)
	{
		e += leon3_putchar(str[i]);
		i++;
	}

	return e;
}

int8_t leon3_print_uint8(uint8_t i)
{
	uint32_t e = 0;
	char c;
	int aux;
//La idea del bucle es buena, pero luego no lo usas
//Una variable de control como first_digit te puede ayudar a evitar los ceros a la izquierda
//sin necesidad de las comparaciones (i>=100) i(>=10) etc.
//int8_t first_digit=0; //detects first digit has been printed, so any 0 must be also printed
//Si además usas aux=aux/10; al final del bucle, no necesitarías los if
//int aux=100; /init aux to 100 to start getting hundreds...


	while (i > 0 && (!e))
	{
		if (i >= 100)
		{
			aux = i / 100;
			i -= 100 * aux;
			e += leon3_putchar(aux + '0');

			aux = i / 10;
			i -= 100 * aux;
			e += leon3_putchar(aux + '0');

			aux = i;
			i = 0;
			e += leon3_putchar(aux + '0');
		}
		else if (i >= 10)
		{
			aux = i / 10;
			i -= 10 * aux;
			e += leon3_putchar(aux + '0');

			aux = i;
			i -= aux;
			e += leon3_putchar(aux + '0');
		}
		else
		{
			aux = i;
			i -= aux;
			e += leon3_putchar(aux + '0');
		}
	}
}

