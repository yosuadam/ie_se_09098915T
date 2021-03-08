#include "leon3_uart.h"
int main()
{
	leon3_putchar('p');
	leon3_putchar('2');
	leon3_putchar('\n');
	
	return 0;
}
/*
int main()
{
	int i=0;
	char aux='0';
	
	for (i=0; i<10; i++)
	{
		leon3_putchar(aux); leon3_putchar('\n');
		aux++;
	}
	
	return 0;
}
*/
