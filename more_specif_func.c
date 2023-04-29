#include "main.h"
/**
 * binary_specif - Converts a string to binary
 * @nump: input string
 * Return: binary string
 */

char *binary_specif(va_list nump)
{
	unsigned int nmb, newnmb;
	int i, j;
	char *binaryPnt;
	int binaryNum[32];

	nmb = va_arg(nump, unsigned int);
	newnmb = nmb;
	i = 0;
	while (nmb > 0)
	{
		binaryNum[i] = nmb % 2;
		nmb = nmb / 2;
		i++;
	}

	binaryPnt = malloc((i + 1) * sizeof(char));
	if (newnmb == 0)
	{
		binaryPnt[0] = '0';
		binaryPnt[1] = '\0';
		return (binaryPnt);
	}
	if (!binaryPnt)
		return (NULL);
	i--;
	for (j = 0; i >= 0; j++, i--)
	{
		binaryPnt[j] = (binaryNum[i] + '0');
		if (i == 0)
			binaryPnt[j] = (binaryNum[i] + '0');
	}
	binaryPnt[j] = '\0';

	return (binaryPnt);
}


/**
 * unsigned_specif - print all the unsigned integers
 * @unint: digit
 * Return: pointer
 */
char *unsigned_specif(va_list unint)
{
	unsigned int i, reset, temp, expo, count;
	char *str;

	reset = va_arg(unint, unsigned int);
	count = i = 0;
	expo = 1;
	temp = reset;
	for (; temp >= 10; count++)
		expo *= 10, temp /= 10;

	str = malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (expo >= 1)
	{
		str[i++] = (((reset / expo) % 10) + '0');
		expo /= 10;
	}
	return (str);
}


/**
 * octal_specif - converts decimal to octal
 * @num: octal number to print
 * Return: pointer to string
 */

char *octal_specif(va_list num)
{
	unsigned long int expo, temp, rst, oct, i;
	char *str;

	oct = va_arg(num, unsigned long int);
	rst = i = 0;
	expo = 1;

	for (; oct; i++)
		rst += (oct % 8) * expo, oct /= 8, expo *= 10;

	temp = i;
	expo /= 10;
	str = malloc(temp * sizeof(char) + 1);

	if (str == NULL)
		return (NULL);

	for (i = 0 ; i < temp; i++)
	{
		str[i] = ((rst / expo) % 10) + '0';
		expo /= 10;
	}
	str[i] = '\0';
	return (str);
}

/**
 * hexa_specif - convert int to hex
 * @hnum: integer
 * Return: hex
 */

char *hexa_specif(va_list hnum)
{
	char *hexaNum;
	unsigned int i, temp, arg, hold, size;

	arg = va_arg(hnum, unsigned int);

	for (hold = arg, size = 0; hold; hold /= 16)
		size++;
	hexaNum = malloc((size + 1) * sizeof(char));
	if (hexaNum == NULL)
		return (NULL);
	for (i = 0; arg; arg /= 16, i++)
	{
		temp = arg % 16;
		if (temp < 10)
			hexaNum[i] = (temp + '0');
		else
			hexaNum[i] = (temp + 'a' - 10);
	}
	return (rev_string(hexaNum));
}

/**
 * Hexa_specif - convert int to  Hexa
 * @hnum: integer
 * Return: hex
 */

char *Hexa_specif(va_list hnum)
{
	char *hexaNum;
	unsigned int i, temp, arg, hold, size;

	arg = va_arg(hnum, unsigned int);

	for (hold = arg, size = 0; hold; hold /= 16)
		size++;
	hexaNum = malloc((size + 1) * sizeof(char));
	if (hexaNum == NULL)
		return (NULL);
	for (i = 0; arg; arg /= 16, i++)
	{
		temp = arg % 16;
		if (temp < 10)
			hexaNum[i] = (temp + '0');
		else
			hexaNum[i] = (temp + 'A' - 10);
	}
	return (rev_string(hexaNum));
}
