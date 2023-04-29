#include "main.h"
/**
 * binary_specif - converts a string to binary
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
