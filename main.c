#include "ft_printf.h"

#include <time.h>

void test_main();

int main()
{
	// test_main();

	char *cmd[5] = {"{%ll20.15d}", "{%l20.15d}", "{%20.15d}", "{%h20.15d}", "{%hh20.15d}"};
	//int value = 42;
	long long value = 1564891455657;

	for (int i =0; i < 5; i++)
	{
		printf(" -> THEM : [%d]\n", printf(cmd[i], value));
		ft_printf(" ->  OUR : [%d]\n", ft_printf(cmd[i], value));
	}
	return (0);
}
