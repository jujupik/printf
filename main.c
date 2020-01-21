#include "ft_printf.h"

#include <time.h>

void test_main();

int main()
{
	// test_main();
	int i = 0;
	char *cmd = "{%-4.*d}" ;
	//char *cmd[5] = {"{%ll20.15d}", "{%l20.15d}", "{%20.15d}", "{%h20.15d}", "{%hh20.15d}"};
	//int value = 42;
	long long value = -135;

	while (i == 0)
	{
		printf(" -> THEM : [%d]\n", printf(cmd, -4,value));
		ft_printf(" ->  OUR : [%d]\n", ft_printf(cmd, -4, value));
		while (i == 0)
			i = 0;
	}
	return (0);
}
