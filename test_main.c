#include "ft_printf.h"

#include <time.h>

int generate_nbr(int min, int max)
{
	return ((rand() % (max - min + 1)) + min);
}

static void set_flag_str(char **str, int padding, int precision, BOOL *wildcard1, BOOL *wildcard2)
{
	BOOL sharp = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	BOOL zero = (generate_nbr(0, 1) == 0 ? FALSE : FALSE);
	BOOL minus = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	BOOL plus = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	BOOL space = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	BOOL point = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	BOOL padding_bool = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	BOOL precision_bool = (generate_nbr(0, 1) == 0 ? FALSE : TRUE);
	int modifier_value = generate_nbr(2, 2);

	if (sharp == TRUE)
		ft_str_replace_back(str, "#");
	if (zero == TRUE)
		ft_str_replace_back(str, "0");
	if (minus == TRUE)
		ft_str_replace_back(str, "-");
	if (space == TRUE)
		ft_str_replace_back(str, " ");
	if (plus == TRUE)
		ft_str_replace_back(str, "+");
	if (padding_bool == TRUE)
	{
		if (*wildcard1 == FALSE)
		{
			char *tmp = ft_itoa(padding);
			ft_str_replace_back(str, tmp);
			free(tmp);
		}
		else
			ft_str_replace_back(str, "*");
	}
	else
		*wildcard1 = FALSE;
	if (point == TRUE)
		ft_str_replace_back(str, ".");
	else
		*wildcard2 = FALSE;
	if (precision_bool == TRUE && point == TRUE)
	{
		if (*wildcard2 == FALSE)
		{
			char *tmp = ft_itoa(precision);
			ft_str_replace_back(str, tmp);
			free(tmp);
		}
		else
			ft_str_replace_back(str, "*");
	}
	if (modifier_value != 2)
	{
		if (modifier_value == 0)
			ft_str_replace_back(str, "hh");
		if (modifier_value == 1)
			ft_str_replace_back(str, "h");
		if (modifier_value == 3)
			ft_str_replace_back(str, "l");
		if (modifier_value == 4)
			ft_str_replace_back(str, "ll");
	}
}

#define TEST_SIZE 500

void test_flag_int(int nb_test, BOOL flag, char *test)
{
	char tmp1[TEST_SIZE];
	char tmp2[TEST_SIZE];

	for (int i = 0; i < nb_test; i++)
	{
		int value = generate_nbr(-100000, 100000);
		BOOL wildcard1 = (generate_nbr(0, 1) == 0 ? TRUE : FALSE);
		BOOL wildcard2 = (generate_nbr(0, 1) == 0 ? TRUE : FALSE);
		int padding = generate_nbr(0, 30);
		int precision = generate_nbr(0, 30);

		char *str = ft_strdup("[%");
		if (flag == TRUE)
			set_flag_str(&str, padding, precision, &wildcard1, &wildcard2);

		ft_str_replace_back(&str, test);
		ft_str_replace_back(&str, "]");


		int ret1 = 0;
		int ret2 = 0;

		if (flag == TRUE && wildcard1 == TRUE && wildcard2 == TRUE)
		{
			ret1 = sprintf(tmp1, str, padding, precision, value);
			ret2 = ft_sprintf(tmp2, str, padding, precision, value);
		}
		else if (flag == TRUE && wildcard1 == TRUE && wildcard2 == FALSE)
		{
			ret1 = sprintf(tmp1, str, padding, value);
			ret2 = ft_sprintf(tmp2, str, padding, value);
		}
		else if (flag == TRUE && wildcard1 == FALSE && wildcard2 == TRUE)
		{
			ret1 = sprintf(tmp1, str, precision, value);
			ret2 = ft_sprintf(tmp2, str, precision, value);
		}
		else
		{
			ret1 = sprintf(tmp1, str, value);
			ret2 = ft_sprintf(tmp2, str, value);
		}

		if (ret1 != ret2 || ft_strcmp(tmp1, tmp2) != 0)
		{
			printf("|| Error with flag %s with value [%d] ||\n", str, value);
			printf("Them : {%s} -> %d\n", tmp1, ret1);
			printf("Our  : {%s} -> %d\n\n", tmp2, ret2);
		}

		free(str);
	}
}

void test_flag_c(int nb_test, BOOL flag)
{
	char tmp1[TEST_SIZE];
	char tmp2[TEST_SIZE];

	for (int i = 0; i < nb_test; i++)
	{
		char value = generate_nbr(0, 127);
		BOOL wildcard1 = (generate_nbr(0, 1) == 0 ? FALSE : FALSE);
		BOOL wildcard2 = (generate_nbr(0, 1) == 0 ? FALSE : FALSE);
		int padding = generate_nbr(0, 30);
		int precision = generate_nbr(0, 30);

		char *str = ft_strdup("[%");
		if (flag == TRUE)
			set_flag_str(&str, padding, precision, &wildcard1, &wildcard2);
		ft_str_replace_back(&str, "c]");

		int ret1 = 0;
		int ret2 = 0;

		if (flag == TRUE && wildcard1 == TRUE && wildcard2 == TRUE)
		{
			ret1 = sprintf(tmp1, str, padding, precision, value);
			ret2 = ft_sprintf(tmp2, str, padding, precision, value);
		}
		else if (flag == TRUE && wildcard1 == TRUE && wildcard2 == FALSE)
		{
			ret1 = sprintf(tmp1, str, padding, value);
			ret2 = ft_sprintf(tmp2, str, padding, value);
		}
		else if (flag == TRUE && wildcard1 == FALSE && wildcard2 == TRUE)
		{
			ret1 = sprintf(tmp1, str, precision, value);
			ret2 = ft_sprintf(tmp2, str, precision, value);
		}
		else
		{
			ret1 = sprintf(tmp1, str, value);
			ret2 = ft_sprintf(tmp2, str, value);
		}

		if (ret1 != ret2 || ft_strcmp(tmp1, tmp2) != 0)
		{
			printf("|| Error with flag %s with value [%c] ||\n", str, value);
			printf("Them : {%s} -> %d\n", tmp1, ret1);
			printf("Our  : {%s} -> %d\n\n", tmp2, ret2);
		}

		free(str);
	}
}

void test_flag_s(int nb_test, BOOL flag)
{
	char tmp1[TEST_SIZE];
	char tmp2[TEST_SIZE];
	char value[80];

	for (int i = 0; i < nb_test; i++)
	{
		int len = generate_nbr(20, 60);
		for (int j = 0; j < len; j++)
			value[j] = generate_nbr(30, 127);
		value[len] = '\0';
		BOOL wildcard1 = (generate_nbr(0, 1) == 0 ? TRUE : FALSE);
		BOOL wildcard2 = (generate_nbr(0, 1) == 0 ? TRUE : FALSE);
		int padding = generate_nbr(0, 30);
		int precision = generate_nbr(0, 30);

		char *str = ft_strdup("[%");
		if (flag == TRUE)
			set_flag_str(&str, padding, precision, &wildcard1, &wildcard2);
		ft_str_replace_back(&str, "s]");

		int ret1 = 0;
		int ret2 = 0;

		if (flag == TRUE && wildcard1 == TRUE && wildcard2 == TRUE)
		{
			ret1 = sprintf(tmp1, str, padding, precision, value);
			ret2 = ft_sprintf(tmp2, str, padding, precision, value);
		}
		else if (flag == TRUE && wildcard1 == TRUE && wildcard2 == FALSE)
		{
			ret1 = sprintf(tmp1, str, padding, value);
			ret2 = ft_sprintf(tmp2, str, padding, value);
		}
		else if (flag == TRUE && wildcard1 == FALSE && wildcard2 == TRUE)
		{
			ret1 = sprintf(tmp1, str, precision, value);
			ret2 = ft_sprintf(tmp2, str, precision, value);
		}
		else
		{
			ret1 = sprintf(tmp1, str, value);
			ret2 = ft_sprintf(tmp2, str, value);
		}

		if (ret1 != ret2 || ft_strcmp(tmp1, tmp2) != 0)
		{
			printf("|| Error with flag %s with value [%s] ||\n", str, value);
			printf("Them : {%s} -> %d\n", tmp1, ret1);
			printf("Our  : {%s} -> %d\n\n", tmp2, ret2);
		}
		free(str);
	}
}

void test_main()
{
	srand(time(NULL));

	int nb_test = 20000000;

	// test_flag_int(nb_test, TRUE, "d");
	// test_flag_int(nb_test, TRUE, "i");
	// test_flag_int(nb_test, TRUE, "o");
	// test_flag_int(nb_test, TRUE, "u");
	// test_flag_int(nb_test, TRUE, "x");
	 test_flag_int(nb_test, TRUE, "X");
	// test_flag_int(nb_test, TRUE, "p");
	//test_flag_c(nb_test, TRUE);
	// test_flag_s(nb_test, TRUE);
}
