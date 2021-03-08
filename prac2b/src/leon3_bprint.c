#include "leon3_bprint.h"

int8_t leon3_print_string(char* str)
{
	uint32_t e = 0;
	int i = 0;

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

