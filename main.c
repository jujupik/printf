#include "ft_printf.h"

#include <time.h>

void test_main();

int main()
{
	// test_main();

	char *cmd = "{%*7s}";
	//int value = 42;
	char *value = "blab";


	printf(" -> THEM : [%d]\n", printf(cmd, -12,  value));
	printf(" ->  OUR : [%d]\n", ft_printf(cmd, -12, value));
	return (0);
}
