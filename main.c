#include "ft_printf.h"

#include <time.h>

void test_main();

int main()
{
	// test_main();
	// int i = 0;
	char *cmd = "{%-4c}" ;
	//char *cmd[5] = {"{%ll20.15d}", "{%l20.15d}", "{%20.15d}", "{%h20.15d}", "{%hh20.15d}"};
	char value = '\0';


	printf(" -> THEM : [%d]\n", printf(cmd, (char)(value)));
	ft_printf(" ->  OUR : [%d]\n", ft_printf(cmd, (char)(value)));
	return (0);
}
